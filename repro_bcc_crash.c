#include <linux/in6.h>
#include <net/sock.h>

#define alwaysinline inline __attribute__((__always_inline__))

static alwaysinline int is_special(struct in6_addr* daddr) {
    // This segfaults
    __u8 byte = daddr->s6_addr[4];

    // This doesn't segfault
    // __u8 byte = (daddr->s6_addr)[4];
    if (byte == 0xd0) {
        return 1;
    } else {
        return 0;
    }
}

int tcp_connect_kprobe(struct pt_regs* ctx) {
    struct sock* skp = (struct sock*)PT_REGS_PARM1(ctx);
    return is_special(&skp->sk_v6_daddr);
}
