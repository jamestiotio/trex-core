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

#ifndef __BPF_API_H__
#define __BPF_API_H__

#include <stdint.h>

typedef void * bpf_h;

#ifdef __cplusplus
extern "C" {
#endif

bpf_h
bpf_compile(const char *bpf_filter);


void
bpf_destroy(bpf_h bpf);


int
bpf_run(bpf_h bpf, const char *buffer, uint32_t len);


#ifdef __cplusplus
}
#endif

#endif /* __BPF_API_H__*/
