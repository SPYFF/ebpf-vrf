#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_endian.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <linux/ip.h>
#include <sys/socket.h>
#include <linux/socket.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <string.h>

SEC("cgroup/connect4")
int set_vrf(struct bpf_sock_addr *sk)
{
	char dev[] = "wifi-vrf";

	if(bpf_get_prandom_u32() & 1)
		bpf_setsockopt(sk, SOL_SOCKET, SO_BINDTODEVICE, dev, sizeof(dev));

	return 1;
}

char _license[] SEC("license") = "GPL";

