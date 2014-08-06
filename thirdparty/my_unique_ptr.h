#include <tuple>
#include <type_traits>
#include <utility>

template <typename T>
struct default_deleter {
    default_deleter() {}

    template <typename U>
    default_deleter(const default_deleter<U>&) {}

    void operator()(T* ptr) const {
        static_assert(sizeof(T) > 0, "Can not delete a incomplete type");
        delete ptr;
        ptr = nullptr;
    }
};

template <typename T>
struct default_deleter<T[]> {
    void operator()(T* ptr) const {
        static_assert(sizeof(ptr) > 0, "Can not delete an incomplete type");
        delete[] ptr;
        ptr = nullptr;
    }
};

template <typename T, typename deleter = default_deleter<T>>
class unique_ptr {
public:
    typedef T* pointer;
public:
    unique_ptr() : _ptr(pointer()), _deleter(deleter()) {
    }

    explicit unique_ptr(pointer _p) : _ptr(_p), _deleter(deleter()) {
    }

    unique_ptr(unique_ptr&& _u) : _ptr(_u.release()),
            _deleter(std::forward<deleter>(_u.get_deleter())) {
    }

    ~unique_ptr() {
        reset();
    }

    unique_ptr& operator=(unique_ptr&& _u) {
        reset(_u.release());
        get_deleter() = std::move(_u.get_deleter());
        return *this;
    }

    pointer release() {
        pointer p = get();
        _ptr = nullptr;
        return p;
    }

    void reset(pointer _p = pointer()) {
        if (_p != get()) {
            get_deleter()(get());
            _ptr = _p;
        }
    }

    pointer get() const {
        return _ptr;
    }

    pointer operator->() const {
        return get();
    }

    typename std::add_lvalue_reference<T>::type operator*() const {
        return *get();
    }

    typename std::add_lvalue_reference<deleter>::type get_deleter() {
        return _deleter;
    }

private:
    // Disallow copy from lvalue;
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

private:
    pointer _ptr;
    deleter _deleter;
};
