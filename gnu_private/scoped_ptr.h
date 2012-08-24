template <typename T>
inline void check_delete(T* x) {
    typedef char type_must_be_complete[sizeof(T)?1:-1];
    (void)sizeof(type_must_be_complete);

    delete x;
}

template <class T>
struct checked_deleter {
    typedef void result_type;
    typedef T* argument_type;
    void operator()(T* x)const {
        check_delete(x);
    }
};

template <typename T>
class scoped_ptr {
private:
    T* px;
    DISALLOW_COPY_AND_ASSIGN(scoped_ptr);
    typedef scoped_ptr<T> this_type;

public:
    typedef T element_type;
    explicit scoped_ptr(T* p) : px(p) {
    }

    ~scoped_ptr() {
        checked_deleter(p);
    }

    void reset(T* p = 0) {
        this_type(p).swap(*this);
    }

    void swap(scoped_ptr& b) {
        T* tmp  = b.px;
        b.px  = px;
        px = tmp;
    }

    T& operator*() const {
        return *px;
    }

    T* operator->() const {
        return px;
    }
    T* get() {
        return px;
    }

    // add release
    T* release() {
        T* tmp = px;
        px = 0;
        return tmp;
    }
};

