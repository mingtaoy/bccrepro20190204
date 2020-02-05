#include <iostream>
#include <bcc/bpf_module.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " PROG\n";
    return 1;
  }
  const char* prog = argv[1];

  ebpf::BPFModule module(0);
  (void)module.load_c(prog, nullptr, 0);
}

