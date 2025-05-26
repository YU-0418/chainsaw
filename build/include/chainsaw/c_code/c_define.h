#ifndef CHAINSAW_C_CODE_C_DEFINE_H
#define CHAINSAW_C_CODE_C_DEFINE_H

#define dbg(data) printf("%s\n", #data)
#define dbg_c(data) printf("%5s -> [%c]\n", #data, data)
#define dbg_s(data) printf("%5s -> [%s]\n", #data, data)
#define dbg_d(data) printf("%5s -> [%d]\n", #data, data)
#define dbg_f(data) printf("%5s -> [%f]\n", #data, data)
#define dbg_lf(data) printf("%5s -> [%lf]\n", #data, data)
#define dbg_p(data) printf("%5s -> %p\n", #data, &data)

#endif // !CHAINSAW_C_CODE_C_DEFINE_H
