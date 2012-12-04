
#ifndef STARBOY
#define STARBOY

#undef LIKELY
#undef UNLIKELY


#if defined(__GNUC__) && __GNUC__ >= 4
#define LIKELY(x) (__builtin_expect((x), 1))
#define UNLIKELY(x) (__builtin_expect((x), 0))
#else
#define LIKELY(x)
#define UNLIKELY(x)
#endif

#endif
