/*
 * Copyright (c) 1997 - 2001 Kungliga Tekniska Högskolan
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

#if defined(_MSC_VER)
# pragma warning(disable: 4646)
# pragma warning(disable: 4716)
#endif

#include "krb5_locl.h"
#include <err.h>

static krb5_error_code _warnerr(krb5_context context, int do_errtext,
	 krb5_error_code code, int level, const char *fmt, va_list ap)
	__attribute__ ((__format__ (__printf__, 5, 0)));

static krb5_error_code
_warnerr(krb5_context context, int do_errtext,
	 krb5_error_code code, int level, const char *fmt, va_list ap)
{
    if (do_errtext)
        return heim_vwarn(context ? context->hcontext : NULL, code, fmt, ap);
    else
        return heim_vwarnx(context ? context->hcontext : NULL, fmt, ap);
}

#define FUNC_NORET(ETEXT, CODE, LEVEL)                                 \
    va_list ap;                                                        \
    va_start(ap, fmt);                                                 \
    (void) _warnerr(context, ETEXT, CODE, LEVEL, fmt, ap);             \
    va_end(ap);

#undef __attribute__
#define __attribute__(X)

/**
 * Log a warning to the log, default stderr, include the error from
 * the last failure.
 *
 * @param context A Kerberos 5 context.
 * @param code error code of the last error
 * @param fmt message to print
 * @param ap arguments
 *
 * @ingroup krb5_error
 */

KRB5_LIB_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_vwarn(krb5_context context, krb5_error_code code,
	   const char *fmt, va_list ap)
     __attribute__ ((__format__ (__printf__, 3, 0)))
{
    return heim_vwarn(context ? context->hcontext : NULL, code, fmt, ap);
}

/**
 * Log a warning to the log, default stderr, include the error from
 * the last failure.
 *
 * @param context A Kerberos 5 context.
 * @param code error code of the last error
 * @param fmt message to print
 *
 * @ingroup krb5_error
 */

KRB5_LIB_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_warn(krb5_context context, krb5_error_code code, const char *fmt, ...)
     __attribute__ ((__format__ (__printf__, 3, 4)))
{
    krb5_error_code ret;
    va_list ap;

    va_start(ap, fmt);
    ret = krb5_vwarn(context, code, fmt, ap);
    va_end(ap);
    return ret;
}

/**
 * Log a warning to the log, default stderr.
 *
 * @param context A Kerberos 5 context.
 * @param fmt message to print
 * @param ap arguments
 *
 * @ingroup krb5_error
 */

KRB5_LIB_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_vwarnx(krb5_context context, const char *fmt, va_list ap)
     __attribute__ ((__format__ (__printf__, 2, 0)))
{
    return heim_vwarnx(context ? context->hcontext : NULL, fmt, ap);
}

/**
 * Log a warning to the log, default stderr.
 *
 * @param context A Kerberos 5 context.
 * @param fmt message to print
 *
 * @ingroup krb5_error
 */

KRB5_LIB_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_warnx(krb5_context context, const char *fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)))
{
    krb5_error_code ret;
    va_list ap;

    va_start(ap, fmt);
    ret = krb5_vwarnx(context, fmt, ap);
    va_end(ap);
    return ret;
}

/**
 * Log a warning to the log, default stderr, include bthe error from
 * the last failure and then exit.
 *
 * @param context A Kerberos 5 context
 * @param eval the exit code to exit with
 * @param code error code of the last error
 * @param fmt message to print
 * @param ap arguments
 *
 * @ingroup krb5_error
 */

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_verr(krb5_context context, int eval, krb5_error_code code,
	  const char *fmt, va_list ap)
     __attribute__ ((__noreturn__, __format__ (__printf__, 4, 0)))
{
    _warnerr(context, 1, code, 0, fmt, ap);
    exit(eval);
    UNREACHABLE(return 0);
}

/**
 * Log a warning to the log, default stderr, include bthe error from
 * the last failure and then exit.
 *
 * @param context A Kerberos 5 context
 * @param eval the exit code to exit with
 * @param code error code of the last error
 * @param fmt message to print
 *
 * @ingroup krb5_error
 */

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_err(krb5_context context, int eval, krb5_error_code code,
	 const char *fmt, ...)
     __attribute__ ((__noreturn__, __format__ (__printf__, 4, 5)))
{
    FUNC_NORET(1, code, 0);
    exit(eval);
    UNREACHABLE(return 0);
}

/**
 * Log a warning to the log, default stderr, and then exit.
 *
 * @param context A Kerberos 5 context
 * @param eval the exit code to exit with
 * @param fmt message to print
 * @param ap arguments
 *
 * @ingroup krb5_error
 */

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_verrx(krb5_context context, int eval, const char *fmt, va_list ap)
     __attribute__ ((__noreturn__, __format__ (__printf__, 3, 0)))
{
    _warnerr(context, 0, 0, 0, fmt, ap);
    exit(eval);
    UNREACHABLE(return 0);
}

/**
 * Log a warning to the log, default stderr, and then exit.
 *
 * @param context A Kerberos 5 context
 * @param eval the exit code to exit with
 * @param fmt message to print
 *
 * @ingroup krb5_error
 */

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_errx(krb5_context context, int eval, const char *fmt, ...)
     __attribute__ ((__noreturn__, __format__ (__printf__, 3, 4)))
{
    FUNC_NORET(0, 0, 0);
    exit(eval);
    UNREACHABLE(return 0);
}

/**
 * Log a warning to the log, default stderr, include bthe error from
 * the last failure and then abort.
 *
 * @param context A Kerberos 5 context
 * @param code error code of the last error
 * @param fmt message to print
 * @param ap arguments
 *
 * @ingroup krb5_error
 */

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_vabort(krb5_context context, krb5_error_code code,
	    const char *fmt, va_list ap)
     __attribute__ ((__noreturn__, __format__ (__printf__, 3, 0)))
{
    _warnerr(context, 1, code, 0, fmt, ap);
    abort();
    UNREACHABLE(return 0);
}

/**
 * Log a warning to the log, default stderr, include the error from
 * the last failure and then abort.
 *
 * @param context A Kerberos 5 context
 * @param code error code of the last error
 * @param fmt message to print
 * @param ... arguments for format string
 *
 * @ingroup krb5_error
 */

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_abort(krb5_context context, krb5_error_code code, const char *fmt, ...)
     __attribute__ ((__noreturn__, __format__ (__printf__, 3, 4)))
{
    FUNC_NORET(1, code, 0);
    abort();
    UNREACHABLE(return 0);
}

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_vabortx(krb5_context context, const char *fmt, va_list ap)
     __attribute__ ((__noreturn__, __format__ (__printf__, 2, 0)))
{
    _warnerr(context, 0, 0, 0, fmt, ap);
    abort();
    UNREACHABLE(return 0);
}

/**
 * Log a warning to the log, default stderr, and then abort.
 *
 * @param context A Kerberos 5 context
 * @param fmt printf format string of message to print
 * @param ... arguments for format string
 *
 * @ingroup krb5_error
 */

KRB5_LIB_NORETURN_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_abortx(krb5_context context, const char *fmt, ...)
     __attribute__ ((__noreturn__, __format__ (__printf__, 2, 3)))
{
    FUNC_NORET(0, 0, 0);
    abort();
    UNREACHABLE(return 0);
}

/**
 * Set the default logging facility.
 *
 * @param context A Kerberos 5 context
 * @param fac Facility to use for logging.
 *
 * @ingroup krb5_error
 */

KRB5_LIB_FUNCTION krb5_error_code KRB5_LIB_CALL
krb5_set_warn_dest(krb5_context context, krb5_log_facility *fac)
{
    return heim_set_warn_dest(context->hcontext, fac);
}

/**
 * Get the default logging facility.
 *
 * @param context A Kerberos 5 context
 *
 * @ingroup krb5_error
 */

KRB5_LIB_FUNCTION krb5_log_facility * KRB5_LIB_CALL
krb5_get_warn_dest(krb5_context context)
{
    return heim_get_warn_dest(context->hcontext);
}
