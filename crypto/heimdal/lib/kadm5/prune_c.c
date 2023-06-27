/*
 * Copyright (c) 2018 Cesnet z.s.p.o.
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

#include "kadm5_locl.h"

RCSID("$Id$");

kadm5_ret_t
kadm5_c_prune_principal(void *server_handle, krb5_principal princ, int kvno)
{
    kadm5_client_context *context = server_handle;
    kadm5_ret_t ret, ret2;
    krb5_storage *sp = NULL;
    unsigned char buf[1024];
    krb5_data reply;

    krb5_data_zero(&reply);
    ret = _kadm5_connect(server_handle, 1 /* want_write */);
    if (ret == 0 && (sp = krb5_storage_from_mem(buf, sizeof(buf))) == NULL)
        ret = krb5_enomem(context->context);
    if (ret == 0)
        ret = krb5_store_int32(sp, kadm_prune);
    if (ret == 0)
        ret = krb5_store_principal(sp, princ);
    if (ret == 0)
        ret = krb5_store_int32(sp, kvno);
    if (ret == 0)
        ret = _kadm5_client_send(context, sp);
    if (ret == 0)
        ret = _kadm5_client_recv(context, &reply);
    krb5_storage_free(sp);
    sp = NULL;
    if (ret == 0 && (sp = krb5_storage_from_data(&reply)) == NULL)
        ret = krb5_enomem(context->context);
    if (ret == 0)
        ret = krb5_ret_int32(sp, &ret2);
    if (ret == 0) {
        krb5_clear_error_message(context->context);
        ret = ret2;
    }
    krb5_data_free(&reply);
    krb5_storage_free(sp);
    return ret;
}
