/*
 Itay Marom
 Cisco Systems, Inc.
*/

/*
Copyright (c) 2015-2015 Cisco Systems, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "bpf_api.h"

#include "pcap-int.h"
#include <pcap/bpf.h>
#include <stdlib.h>
#include <assert.h>

bpf_h
bpf_compile(const char *bpf_filter) {
    struct bpf_program *program = (struct bpf_program *)malloc(sizeof(struct bpf_program));
    assert(program);
    
    /* compile - no attach to PCAP device */
    int rc = pcap_compile_nopcap(65535, DLT_EN10MB, program, bpf_filter, 1, 0);
    if (rc != 0) {
        free(program);
        return NULL;
    }

    return (bpf_h)program;
}


void
bpf_destroy(bpf_h bpf) {
    free(bpf);
}


int
bpf_run(bpf_h bpf, const char *buffer, uint32_t len) {
    
    struct bpf_program *program = (struct bpf_program *)bpf;
    assert(program);
    assert(buffer);
    assert(len > 0);
    
    const struct bpf_insn *fcode = program->bf_insns;
    return bpf_filter(fcode, buffer, len, len);
}
