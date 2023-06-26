/*
 * Copyright (c) 2006 - 2007 Kungliga Tekniska Högskolan
 * (Royal Institute of Technology, Stockholm, Sweden).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "hx_locl.h"

static int
test_name(hx509_context context, const char *name)
{
    hx509_name n;
    char *s;
    int ret;

    ret = hx509_parse_name(context, name, &n);
    if (ret)
	return 1;

    ret = hx509_name_to_string(n, &s);
    if (ret)
	return 1;

    if (strcmp(s, name) != 0)
	return 1;

    hx509_name_free(&n);
    free(s);

    return 0;
}

static int
test_name_fail(hx509_context context, const char *name)
{
    hx509_name n;

    if (hx509_parse_name(context, name, &n) == HX509_NAME_MALFORMED)
	return 0;
    hx509_name_free(&n);
    return 1;
}

static int
test_expand(hx509_context context, const char *name, const char *expected)
{
    hx509_env env = NULL;
    hx509_name n;
    char *s;
    int ret;

    hx509_env_add(context, &env, "uid", "lha");

    ret = hx509_parse_name(context, name, &n);
    if (ret)
	return 1;

    ret = hx509_name_expand(context, n, env);
    hx509_env_free(&env);
    if (ret)
	return 1;

    ret = hx509_name_to_string(n, &s);
    hx509_name_free(&n);
    if (ret)
	return 1;

    ret = strcmp(s, expected) != 0;
    free(s);
    if (ret)
	return 1;

    return 0;
}

char certdata1[] =
    "\x30\x82\x04\x1d\x30\x82\x03\x05\xa0\x03\x02\x01\x02\x02\x10\x4e"
    "\x81\x2d\x8a\x82\x65\xe0\x0b\x02\xee\x3e\x35\x02\x46\xe5\x3d\x30"
    "\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05\x05\x00\x30\x81"
    "\x81\x31\x0b\x30\x09\x06\x03\x55\x04\x06\x13\x02\x47\x42\x31\x1b"
    "\x30\x19\x06\x03\x55\x04\x08\x13\x12\x47\x72\x65\x61\x74\x65\x72"
    "\x20\x4d\x61\x6e\x63\x68\x65\x73\x74\x65\x72\x31\x10\x30\x0e\x06"
    "\x03\x55\x04\x07\x13\x07\x53\x61\x6c\x66\x6f\x72\x64\x31\x1a\x30"
    "\x18\x06\x03\x55\x04\x0a\x13\x11\x43\x4f\x4d\x4f\x44\x4f\x20\x43"
    "\x41\x20\x4c\x69\x6d\x69\x74\x65\x64\x31\x27\x30\x25\x06\x03\x55"
    "\x04\x03\x13\x1e\x43\x4f\x4d\x4f\x44\x4f\x20\x43\x65\x72\x74\x69"
    "\x66\x69\x63\x61\x74\x69\x6f\x6e\x20\x41\x75\x74\x68\x6f\x72\x69"
    "\x74\x79\x30\x1e\x17\x0d\x30\x36\x31\x32\x30\x31\x30\x30\x30\x30"
    "\x30\x30\x5a\x17\x0d\x32\x39\x31\x32\x33\x31\x32\x33\x35\x39\x35"
    "\x39\x5a\x30\x81\x81\x31\x0b\x30\x09\x06\x03\x55\x04\x06\x13\x02"
    "\x47\x42\x31\x1b\x30\x19\x06\x03\x55\x04\x08\x13\x12\x47\x72\x65"
    "\x61\x74\x65\x72\x20\x4d\x61\x6e\x63\x68\x65\x73\x74\x65\x72\x31"
    "\x10\x30\x0e\x06\x03\x55\x04\x07\x13\x07\x53\x61\x6c\x66\x6f\x72"
    "\x64\x31\x1a\x30\x18\x06\x03\x55\x04\x0a\x13\x11\x43\x4f\x4d\x4f"
    "\x44\x4f\x20\x43\x41\x20\x4c\x69\x6d\x69\x74\x65\x64\x31\x27\x30"
    "\x25\x06\x03\x55\x04\x03\x13\x1e\x43\x4f\x4d\x4f\x44\x4f\x20\x43"
    "\x65\x72\x74\x69\x66\x69\x63\x61\x74\x69\x6f\x6e\x20\x41\x75\x74"
    "\x68\x6f\x72\x69\x74\x79\x30\x82\x01\x22\x30\x0d\x06\x09\x2a\x86"
    "\x48\x86\xf7\x0d\x01\x01\x01\x05\x00\x03\x82\x01\x0f\x00\x30\x82"
    "\x01\x0a\x02\x82\x01\x01\x00\xd0\x40\x8b\x8b\x72\xe3\x91\x1b\xf7"
    "\x51\xc1\x1b\x54\x04\x98\xd3\xa9\xbf\xc1\xe6\x8a\x5d\x3b\x87\xfb"
    "\xbb\x88\xce\x0d\xe3\x2f\x3f\x06\x96\xf0\xa2\x29\x50\x99\xae\xdb"
    "\x3b\xa1\x57\xb0\x74\x51\x71\xcd\xed\x42\x91\x4d\x41\xfe\xa9\xc8"
    "\xd8\x6a\x86\x77\x44\xbb\x59\x66\x97\x50\x5e\xb4\xd4\x2c\x70\x44"
    "\xcf\xda\x37\x95\x42\x69\x3c\x30\xc4\x71\xb3\x52\xf0\x21\x4d\xa1"
    "\xd8\xba\x39\x7c\x1c\x9e\xa3\x24\x9d\xf2\x83\x16\x98\xaa\x16\x7c"
    "\x43\x9b\x15\x5b\xb7\xae\x34\x91\xfe\xd4\x62\x26\x18\x46\x9a\x3f"
    "\xeb\xc1\xf9\xf1\x90\x57\xeb\xac\x7a\x0d\x8b\xdb\x72\x30\x6a\x66"
    "\xd5\xe0\x46\xa3\x70\xdc\x68\xd9\xff\x04\x48\x89\x77\xde\xb5\xe9"
    "\xfb\x67\x6d\x41\xe9\xbc\x39\xbd\x32\xd9\x62\x02\xf1\xb1\xa8\x3d"
    "\x6e\x37\x9c\xe2\x2f\xe2\xd3\xa2\x26\x8b\xc6\xb8\x55\x43\x88\xe1"
    "\x23\x3e\xa5\xd2\x24\x39\x6a\x47\xab\x00\xd4\xa1\xb3\xa9\x25\xfe"
    "\x0d\x3f\xa7\x1d\xba\xd3\x51\xc1\x0b\xa4\xda\xac\x38\xef\x55\x50"
    "\x24\x05\x65\x46\x93\x34\x4f\x2d\x8d\xad\xc6\xd4\x21\x19\xd2\x8e"
    "\xca\x05\x61\x71\x07\x73\x47\xe5\x8a\x19\x12\xbd\x04\x4d\xce\x4e"
    "\x9c\xa5\x48\xac\xbb\x26\xf7\x02\x03\x01\x00\x01\xa3\x81\x8e\x30"
    "\x81\x8b\x30\x1d\x06\x03\x55\x1d\x0e\x04\x16\x04\x14\x0b\x58\xe5"
    "\x8b\xc6\x4c\x15\x37\xa4\x40\xa9\x30\xa9\x21\xbe\x47\x36\x5a\x56"
    "\xff\x30\x0e\x06\x03\x55\x1d\x0f\x01\x01\xff\x04\x04\x03\x02\x01"
    "\x06\x30\x0f\x06\x03\x55\x1d\x13\x01\x01\xff\x04\x05\x30\x03\x01"
    "\x01\xff\x30\x49\x06\x03\x55\x1d\x1f\x04\x42\x30\x40\x30\x3e\xa0"
    "\x3c\xa0\x3a\x86\x38\x68\x74\x74\x70\x3a\x2f\x2f\x63\x72\x6c\x2e"
    "\x63\x6f\x6d\x6f\x64\x6f\x63\x61\x2e\x63\x6f\x6d\x2f\x43\x4f\x4d"
    "\x4f\x44\x4f\x43\x65\x72\x74\x69\x66\x69\x63\x61\x74\x69\x6f\x6e"
    "\x41\x75\x74\x68\x6f\x72\x69\x74\x79\x2e\x63\x72\x6c\x30\x0d\x06"
    "\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05\x05\x00\x03\x82\x01\x01"
    "\x00\x3e\x98\x9e\x9b\xf6\x1b\xe9\xd7\x39\xb7\x78\xae\x1d\x72\x18"
    "\x49\xd3\x87\xe4\x43\x82\xeb\x3f\xc9\xaa\xf5\xa8\xb5\xef\x55\x7c"
    "\x21\x52\x65\xf9\xd5\x0d\xe1\x6c\xf4\x3e\x8c\x93\x73\x91\x2e\x02"
    "\xc4\x4e\x07\x71\x6f\xc0\x8f\x38\x61\x08\xa8\x1e\x81\x0a\xc0\x2f"
    "\x20\x2f\x41\x8b\x91\xdc\x48\x45\xbc\xf1\xc6\xde\xba\x76\x6b\x33"
    "\xc8\x00\x2d\x31\x46\x4c\xed\xe7\x9d\xcf\x88\x94\xff\x33\xc0\x56"
    "\xe8\x24\x86\x26\xb8\xd8\x38\x38\xdf\x2a\x6b\xdd\x12\xcc\xc7\x3f"
    "\x47\x17\x4c\xa2\xc2\x06\x96\x09\xd6\xdb\xfe\x3f\x3c\x46\x41\xdf"
    "\x58\xe2\x56\x0f\x3c\x3b\xc1\x1c\x93\x35\xd9\x38\x52\xac\xee\xc8"
    "\xec\x2e\x30\x4e\x94\x35\xb4\x24\x1f\x4b\x78\x69\xda\xf2\x02\x38"
    "\xcc\x95\x52\x93\xf0\x70\x25\x59\x9c\x20\x67\xc4\xee\xf9\x8b\x57"
    "\x61\xf4\x92\x76\x7d\x3f\x84\x8d\x55\xb7\xe8\xe5\xac\xd5\xf1\xf5"
    "\x19\x56\xa6\x5a\xfb\x90\x1c\xaf\x93\xeb\xe5\x1c\xd4\x67\x97\x5d"
    "\x04\x0e\xbe\x0b\x83\xa6\x17\x83\xb9\x30\x12\xa0\xc5\x33\x15\x05"
    "\xb9\x0d\xfb\xc7\x05\x76\xe3\xd8\x4a\x8d\xfc\x34\x17\xa3\xc6\x21"
    "\x28\xbe\x30\x45\x31\x1e\xc7\x78\xbe\x58\x61\x38\xac\x3b\xe2\x01"
    "\x65";

char certdata2[] =
    "\x30\x82\x03\x02\x30\x82\x02\x6b\x02\x10\x39\xca\x54\x89\xfe\x50"
    "\x22\x32\xfe\x32\xd9\xdb\xfb\x1b\x84\x19\x30\x0d\x06\x09\x2a\x86"
    "\x48\x86\xf7\x0d\x01\x01\x05\x05\x00\x30\x81\xc1\x31\x0b\x30\x09"
    "\x06\x03\x55\x04\x06\x13\x02\x55\x53\x31\x17\x30\x15\x06\x03\x55"
    "\x04\x0a\x13\x0e\x56\x65\x72\x69\x53\x69\x67\x6e\x2c\x20\x49\x6e"
    "\x63\x2e\x31\x3c\x30\x3a\x06\x03\x55\x04\x0b\x13\x33\x43\x6c\x61"
    "\x73\x73\x20\x31\x20\x50\x75\x62\x6c\x69\x63\x20\x50\x72\x69\x6d"
    "\x61\x72\x79\x20\x43\x65\x72\x74\x69\x66\x69\x63\x61\x74\x69\x6f"
    "\x6e\x20\x41\x75\x74\x68\x6f\x72\x69\x74\x79\x20\x2d\x20\x47\x32"
    "\x31\x3a\x30\x38\x06\x03\x55\x04\x0b\x13\x31\x28\x63\x29\x20\x31"
    "\x39\x39\x38\x20\x56\x65\x72\x69\x53\x69\x67\x6e\x2c\x20\x49\x6e"
    "\x63\x2e\x20\x2d\x20\x46\x6f\x72\x20\x61\x75\x74\x68\x6f\x72\x69"
    "\x7a\x65\x64\x20\x75\x73\x65\x20\x6f\x6e\x6c\x79\x31\x1f\x30\x1d"
    "\x06\x03\x55\x04\x0b\x13\x16\x56\x65\x72\x69\x53\x69\x67\x6e\x20"
    "\x54\x72\x75\x73\x74\x20\x4e\x65\x74\x77\x6f\x72\x6b\x30\x1e\x17"
    "\x0d\x39\x38\x30\x35\x31\x38\x30\x30\x30\x30\x30\x30\x5a\x17\x0d"
    "\x31\x38\x30\x35\x31\x38\x32\x33\x35\x39\x35\x39\x5a\x30\x81\xc1"
    "\x31\x0b\x30\x09\x06\x03\x55\x04\x06\x13\x02\x55\x53\x31\x17\x30"
    "\x15\x06\x03\x55\x04\x0a\x13\x0e\x56\x65\x72\x69\x53\x69\x67\x6e"
    "\x2c\x20\x49\x6e\x63\x2e\x31\x3c\x30\x3a\x06\x03\x55\x04\x0b\x13"
    "\x33\x43\x6c\x61\x73\x73\x20\x31\x20\x50\x75\x62\x6c\x69\x63\x20"
    "\x50\x72\x69\x6d\x61\x72\x79\x20\x43\x65\x72\x74\x69\x66\x69\x63"
    "\x61\x74\x69\x6f\x6e\x20\x41\x75\x74\x68\x6f\x72\x69\x74\x79\x20"
    "\x2d\x20\x47\x32\x31\x3a\x30\x38\x06\x03\x55\x04\x0b\x13\x31\x28"
    "\x63\x29\x20\x31\x39\x39\x38\x20\x56\x65\x72\x69\x53\x69\x67\x6e"
    "\x2c\x20\x49\x6e\x63\x2e\x20\x2d\x20\x46\x6f\x72\x20\x61\x75\x74"
    "\x68\x6f\x72\x69\x7a\x65\x64\x20\x75\x73\x65\x20\x6f\x6e\x6c\x79"
    "\x31\x1f\x30\x1d\x06\x03\x55\x04\x0b\x13\x16\x56\x65\x72\x69\x53"
    "\x69\x67\x6e\x20\x54\x72\x75\x73\x74\x20\x4e\x65\x74\x77\x6f\x72"
    "\x6b\x30\x81\x9f\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01"
    "\x01\x05\x00\x03\x81\x8d\x00\x30\x81\x89\x02\x81\x81\x00\xaa\xd0"
    "\xba\xbe\x16\x2d\xb8\x83\xd4\xca\xd2\x0f\xbc\x76\x31\xca\x94\xd8"
    "\x1d\x93\x8c\x56\x02\xbc\xd9\x6f\x1a\x6f\x52\x36\x6e\x75\x56\x0a"
    "\x55\xd3\xdf\x43\x87\x21\x11\x65\x8a\x7e\x8f\xbd\x21\xde\x6b\x32"
    "\x3f\x1b\x84\x34\x95\x05\x9d\x41\x35\xeb\x92\xeb\x96\xdd\xaa\x59"
    "\x3f\x01\x53\x6d\x99\x4f\xed\xe5\xe2\x2a\x5a\x90\xc1\xb9\xc4\xa6"
    "\x15\xcf\xc8\x45\xeb\xa6\x5d\x8e\x9c\x3e\xf0\x64\x24\x76\xa5\xcd"
    "\xab\x1a\x6f\xb6\xd8\x7b\x51\x61\x6e\xa6\x7f\x87\xc8\xe2\xb7\xe5"
    "\x34\xdc\x41\x88\xea\x09\x40\xbe\x73\x92\x3d\x6b\xe7\x75\x02\x03"
    "\x01\x00\x01\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05"
    "\x05\x00\x03\x81\x81\x00\x8b\xf7\x1a\x10\xce\x76\x5c\x07\xab\x83"
    "\x99\xdc\x17\x80\x6f\x34\x39\x5d\x98\x3e\x6b\x72\x2c\xe1\xc7\xa2"
    "\x7b\x40\x29\xb9\x78\x88\xba\x4c\xc5\xa3\x6a\x5e\x9e\x6e\x7b\xe3"
    "\xf2\x02\x41\x0c\x66\xbe\xad\xfb\xae\xa2\x14\xce\x92\xf3\xa2\x34"
    "\x8b\xb4\xb2\xb6\x24\xf2\xe5\xd5\xe0\xc8\xe5\x62\x6d\x84\x7b\xcb"
    "\xbe\xbb\x03\x8b\x7c\x57\xca\xf0\x37\xa9\x90\xaf\x8a\xee\x03\xbe"
    "\x1d\x28\x9c\xd9\x26\x76\xa0\xcd\xc4\x9d\x4e\xf0\xae\x07\x16\xd5"
    "\xbe\xaf\x57\x08\x6a\xd0\xa0\x42\x42\x42\x1e\xf4\x20\xcc\xa5\x78"
    "\x82\x95\x26\x38\x8a\x47";

char certdata3[] =
    "\x30\x82\x04\x43\x30\x82\x03\x2b\xa0\x03\x02\x01\x02\x02\x01\x01"
    "\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05\x05\x00\x30"
    "\x7f\x31\x0b\x30\x09\x06\x03\x55\x04\x06\x13\x02\x47\x42\x31\x1b"
    "\x30\x19\x06\x03\x55\x04\x08\x0c\x12\x47\x72\x65\x61\x74\x65\x72"
    "\x20\x4d\x61\x6e\x63\x68\x65\x73\x74\x65\x72\x31\x10\x30\x0e\x06"
    "\x03\x55\x04\x07\x0c\x07\x53\x61\x6c\x66\x6f\x72\x64\x31\x1a\x30"
    "\x18\x06\x03\x55\x04\x0a\x0c\x11\x43\x6f\x6d\x6f\x64\x6f\x20\x43"
    "\x41\x20\x4c\x69\x6d\x69\x74\x65\x64\x31\x25\x30\x23\x06\x03\x55"
    "\x04\x03\x0c\x1c\x54\x72\x75\x73\x74\x65\x64\x20\x43\x65\x72\x74"
    "\x69\x66\x69\x63\x61\x74\x65\x20\x53\x65\x72\x76\x69\x63\x65\x73"
    "\x30\x1e\x17\x0d\x30\x34\x30\x31\x30\x31\x30\x30\x30\x30\x30\x30"
    "\x5a\x17\x0d\x32\x38\x31\x32\x33\x31\x32\x33\x35\x39\x35\x39\x5a"
    "\x30\x7f\x31\x0b\x30\x09\x06\x03\x55\x04\x06\x13\x02\x47\x42\x31"
    "\x1b\x30\x19\x06\x03\x55\x04\x08\x0c\x12\x47\x72\x65\x61\x74\x65"
    "\x72\x20\x4d\x61\x6e\x63\x68\x65\x73\x74\x65\x72\x31\x10\x30\x0e"
    "\x06\x03\x55\x04\x07\x0c\x07\x53\x61\x6c\x66\x6f\x72\x64\x31\x1a"
    "\x30\x18\x06\x03\x55\x04\x0a\x0c\x11\x43\x6f\x6d\x6f\x64\x6f\x20"
    "\x43\x41\x20\x4c\x69\x6d\x69\x74\x65\x64\x31\x25\x30\x23\x06\x03"
    "\x55\x04\x03\x0c\x1c\x54\x72\x75\x73\x74\x65\x64\x20\x43\x65\x72"
    "\x74\x69\x66\x69\x63\x61\x74\x65\x20\x53\x65\x72\x76\x69\x63\x65"
    "\x73\x30\x82\x01\x22\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01"
    "\x01\x01\x05\x00\x03\x82\x01\x0f\x00\x30\x82\x01\x0a\x02\x82\x01"
    "\x01\x00\xdf\x71\x6f\x36\x58\x53\x5a\xf2\x36\x54\x57\x80\xc4\x74"
    "\x08\x20\xed\x18\x7f\x2a\x1d\xe6\x35\x9a\x1e\x25\xac\x9c\xe5\x96"
    "\x7e\x72\x52\xa0\x15\x42\xdb\x59\xdd\x64\x7a\x1a\xd0\xb8\x7b\xdd"
    "\x39\x15\xbc\x55\x48\xc4\xed\x3a\x00\xea\x31\x11\xba\xf2\x71\x74"
    "\x1a\x67\xb8\xcf\x33\xcc\xa8\x31\xaf\xa3\xe3\xd7\x7f\xbf\x33\x2d"
    "\x4c\x6a\x3c\xec\x8b\xc3\x92\xd2\x53\x77\x24\x74\x9c\x07\x6e\x70"
    "\xfc\xbd\x0b\x5b\x76\xba\x5f\xf2\xff\xd7\x37\x4b\x4a\x60\x78\xf7"
    "\xf0\xfa\xca\x70\xb4\xea\x59\xaa\xa3\xce\x48\x2f\xa9\xc3\xb2\x0b"
    "\x7e\x17\x72\x16\x0c\xa6\x07\x0c\x1b\x38\xcf\xc9\x62\xb7\x3f\xa0"
    "\x93\xa5\x87\x41\xf2\xb7\x70\x40\x77\xd8\xbe\x14\x7c\xe3\xa8\xc0"
    "\x7a\x8e\xe9\x63\x6a\xd1\x0f\x9a\xc6\xd2\xf4\x8b\x3a\x14\x04\x56"
    "\xd4\xed\xb8\xcc\x6e\xf5\xfb\xe2\x2c\x58\xbd\x7f\x4f\x6b\x2b\xf7"
    "\x60\x24\x58\x24\xce\x26\xef\x34\x91\x3a\xd5\xe3\x81\xd0\xb2\xf0"
    "\x04\x02\xd7\x5b\xb7\x3e\x92\xac\x6b\x12\x8a\xf9\xe4\x05\xb0\x3b"
    "\x91\x49\x5c\xb2\xeb\x53\xea\xf8\x9f\x47\x86\xee\xbf\x95\xc0\xc0"
    "\x06\x9f\xd2\x5b\x5e\x11\x1b\xf4\xc7\x04\x35\x29\xd2\x55\x5c\xe4"
    "\xed\xeb\x02\x03\x01\x00\x01\xa3\x81\xc9\x30\x81\xc6\x30\x1d\x06"
    "\x03\x55\x1d\x0e\x04\x16\x04\x14\xc5\x7b\x58\xbd\xed\xda\x25\x69"
    "\xd2\xf7\x59\x16\xa8\xb3\x32\xc0\x7b\x27\x5b\xf4\x30\x0e\x06\x03"
    "\x55\x1d\x0f\x01\x01\xff\x04\x04\x03\x02\x01\x06\x30\x0f\x06\x03"
    "\x55\x1d\x13\x01\x01\xff\x04\x05\x30\x03\x01\x01\xff\x30\x81\x83"
    "\x06\x03\x55\x1d\x1f\x04\x7c\x30\x7a\x30\x3c\xa0\x3a\xa0\x38\x86"
    "\x36\x68\x74\x74\x70\x3a\x2f\x2f\x63\x72\x6c\x2e\x63\x6f\x6d\x6f"
    "\x64\x6f\x63\x61\x2e\x63\x6f\x6d\x2f\x54\x72\x75\x73\x74\x65\x64"
    "\x43\x65\x72\x74\x69\x66\x69\x63\x61\x74\x65\x53\x65\x72\x76\x69"
    "\x63\x65\x73\x2e\x63\x72\x6c\x30\x3a\xa0\x38\xa0\x36\x86\x34\x68"
    "\x74\x74\x70\x3a\x2f\x2f\x63\x72\x6c\x2e\x63\x6f\x6d\x6f\x64\x6f"
    "\x2e\x6e\x65\x74\x2f\x54\x72\x75\x73\x74\x65\x64\x43\x65\x72\x74"
    "\x69\x66\x69\x63\x61\x74\x65\x53\x65\x72\x76\x69\x63\x65\x73\x2e"
    "\x63\x72\x6c\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x05"
    "\x05\x00\x03\x82\x01\x01\x00\xc8\x93\x81\x3b\x89\xb4\xaf\xb8\x84"
    "\x12\x4c\x8d\xd2\xf0\xdb\x70\xba\x57\x86\x15\x34\x10\xb9\x2f\x7f"
    "\x1e\xb0\xa8\x89\x60\xa1\x8a\xc2\x77\x0c\x50\x4a\x9b\x00\x8b\xd8"
    "\x8b\xf4\x41\xe2\xd0\x83\x8a\x4a\x1c\x14\x06\xb0\xa3\x68\x05\x70"
    "\x31\x30\xa7\x53\x9b\x0e\xe9\x4a\xa0\x58\x69\x67\x0e\xae\x9d\xf6"
    "\xa5\x2c\x41\xbf\x3c\x06\x6b\xe4\x59\xcc\x6d\x10\xf1\x96\x6f\x1f"
    "\xdf\xf4\x04\x02\xa4\x9f\x45\x3e\xc8\xd8\xfa\x36\x46\x44\x50\x3f"
    "\x82\x97\x91\x1f\x28\xdb\x18\x11\x8c\x2a\xe4\x65\x83\x57\x12\x12"
    "\x8c\x17\x3f\x94\x36\xfe\x5d\xb0\xc0\x04\x77\x13\xb8\xf4\x15\xd5"
    "\x3f\x38\xcc\x94\x3a\x55\xd0\xac\x98\xf5\xba\x00\x5f\xe0\x86\x19"
    "\x81\x78\x2f\x28\xc0\x7e\xd3\xcc\x42\x0a\xf5\xae\x50\xa0\xd1\x3e"
    "\xc6\xa1\x71\xec\x3f\xa0\x20\x8c\x66\x3a\x89\xb4\x8e\xd4\xd8\xb1"
    "\x4d\x25\x47\xee\x2f\x88\xc8\xb5\xe1\x05\x45\xc0\xbe\x14\x71\xde"
    "\x7a\xfd\x8e\x7b\x7d\x4d\x08\x96\xa5\x12\x73\xf0\x2d\xca\x37\x27"
    "\x74\x12\x27\x4c\xcb\xb6\x97\xe9\xd9\xae\x08\x6d\x5a\x39\x40\xdd"
    "\x05\x47\x75\x6a\x5a\x21\xb3\xa3\x18\xcf\x4e\xf7\x2e\x57\xb7\x98"
    "\x70\x5e\xc8\xc4\x78\xb0\x62";


static int
compare_subject(hx509_cert c1, hx509_cert c2, int *l)
{
    hx509_name n1, n2;
    int ret;

    ret = hx509_cert_get_subject(c1, &n1);
    if (ret) return 1;
    ret = hx509_cert_get_subject(c2, &n2);
    if (ret) return 1;

    *l = hx509_name_cmp(n1, n2);
    hx509_name_free(&n1);
    hx509_name_free(&n2);

    return 0;
}

static int
test_compare(hx509_context context)
{
    int ret;
    hx509_cert c1, c2, c3;
    int l0, l1, l2, l3;

    /* check transative properties of name compare function */

    c1 = hx509_cert_init_data(context, certdata1, sizeof(certdata1) - 1, NULL);
    if (c1 == NULL) return 1;

    c2 = hx509_cert_init_data(context, certdata2, sizeof(certdata2) - 1, NULL);
    if (c2 == NULL) return 1;
    
    c3 = hx509_cert_init_data(context, certdata3, sizeof(certdata3) - 1, NULL);
    if (c3 == NULL) return 1;

    ret = compare_subject(c1, c1, &l0);
    if (ret) return 1;
    ret = compare_subject(c1, c2, &l1);
    if (ret) return 1;
    ret = compare_subject(c1, c3, &l2);
    if (ret) return 1;
    ret = compare_subject(c2, c3, &l3);
    if (ret) return 1;

    if (l0 != 0) return 1;
    if (l2 < l1) return 1;
    if (l3 < l2) return 1;
    if (l3 < l1) return 1;

    hx509_cert_free(c1);
    hx509_cert_free(c2);
    hx509_cert_free(c3);

    return 0;
}

static int
test_pkinit_san(hx509_context context, const char *p, const char *realm, ...)
{
    KRB5PrincipalName kn;
    GeneralName gn;
    va_list ap;
    size_t i, sz;
    char *round_trip;
    int ret;

    memset(&kn, 0, sizeof(kn));
    memset(&gn, 0, sizeof(gn));

    ret = _hx509_make_pkinit_san(context, p, &gn.u.otherName.value);
    if (ret == 0)
        ret = decode_KRB5PrincipalName(gn.u.otherName.value.data,
                                       gn.u.otherName.value.length, &kn, &sz);
    if (ret)
        return 1;
    if (strcmp(realm, kn.realm) != 0)
        return 1;

    va_start(ap, realm);
    for (i = 0; i < kn.principalName.name_string.len; i++) {
        const char *s = va_arg(ap, const char *);

        if (s == NULL || strcmp(kn.principalName.name_string.val[i], s) != 0)
            return 1;
    }
    if (va_arg(ap, const char *) != NULL)
        return 1;
    va_end(ap);

    gn.element = choice_GeneralName_otherName;
    gn.u.otherName.type_id.length = 0;
    gn.u.otherName.type_id.components = 0;
    ret = der_copy_oid(&asn1_oid_id_pkinit_san, &gn.u.otherName.type_id);
    if (ret == 0)
        ret = hx509_general_name_unparse(&gn, &round_trip);
    if (ret)
        return 1;
    if (strncmp(round_trip, "otherName: 1.3.6.1.5.2.2 KerberosPrincipalName ",
                sizeof("otherName: 1.3.6.1.5.2.2 KerberosPrincipalName ") - 1))
        return 1;
    if (ret || strcmp(round_trip + sizeof("otherName: 1.3.6.1.5.2.2 KerberosPrincipalName ") - 1, p) != 0)
        return 1;
    free_KRB5PrincipalName(&kn);
    free_GeneralName(&gn);
    free(round_trip);
    return 0;
}

static int
test_pkinit_san_fail(hx509_context context, const char *p)
{
    heim_octet_string os;
    KRB5PrincipalName kn;
    int ret;

    memset(&kn, 0, sizeof(kn));
    ret = _hx509_make_pkinit_san(context, p, &os);
    if (ret == 0) {
        free(os.data);
        return 1;
    }
    return 0;
}


int
main(int argc, char **argv)
{
    hx509_context context;
    int ret = 0;

    ret = hx509_context_init(&context);
    if (ret)
	errx(1, "hx509_context_init failed with %d", ret);

    ret += test_name(context, "CN=foo,C=SE");
    ret += test_name(context, "CN=foo,CN=kaka,CN=FOO,DC=ad1,C=SE");
    ret += test_name(context, "1.2.3.4=foo,C=SE");
    ret += test_name_fail(context, "=");
    ret += test_name_fail(context, "CN=foo,=foo");
    ret += test_name_fail(context, "CN=foo,really-unknown-type=foo");

    ret += test_expand(context, "UID=${uid},C=SE", "UID=lha,C=SE");
    ret += test_expand(context, "UID=foo${uid},C=SE", "UID=foolha,C=SE");
    ret += test_expand(context, "UID=${uid}bar,C=SE", "UID=lhabar,C=SE");
    ret += test_expand(context, "UID=f${uid}b,C=SE", "UID=flhab,C=SE");
    ret += test_expand(context, "UID=${uid}${uid},C=SE", "UID=lhalha,C=SE");
    ret += test_expand(context, "UID=${uid}{uid},C=SE", "UID=lha{uid},C=SE");

    ret += test_compare(context);

    ret += test_pkinit_san(context, "foo@BAR.H5L.SE",
                           "BAR.H5L.SE", "foo", NULL);
    ret += test_pkinit_san(context, "foo\\ bar@BAR.H5L.SE",
                           "BAR.H5L.SE", "foo bar", NULL);
    ret += test_pkinit_san(context, "foo\\/bar@BAR.H5L.SE",
                           "BAR.H5L.SE", "foo/bar", NULL);
    ret += test_pkinit_san(context, "foo/bar@BAR.H5L.SE",
                           "BAR.H5L.SE", "foo", "bar", NULL);
    ret += test_pkinit_san(context, "foo\\tbar@BAR.H5L.SE",
                           "BAR.H5L.SE", "foo\tbar", NULL);
    ret += test_pkinit_san(context, "foo\\nbar@BAR.H5L.SE",
                           "BAR.H5L.SE", "foo\nbar", NULL);
    ret += test_pkinit_san(context, "foo@\\ BAR.H5L.SE",
                           " BAR.H5L.SE", "foo", NULL);
    ret += test_pkinit_san(context, "foo@\\nBAR.H5L.SE",
                           "\nBAR.H5L.SE", "foo", NULL);
    ret += test_pkinit_san_fail(context, "foo\\0bar@BAR.H5L.SE");

    hx509_context_free(&context);

    return !!ret;
}
