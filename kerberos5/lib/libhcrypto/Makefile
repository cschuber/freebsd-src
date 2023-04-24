# $FreeBSD$

PACKAGE=	kerberos-lib

LIB=	hcrypto
LDFLAGS=	-Wl,--no-undefined
VERSION_MAP= ${KRB5DIR}/lib/hcrypto/version-script.map
LIBADD=	com_err asn1 roken crypto heimbase

LTMSOURCES = \
	bncore.c \
	bn_mp_init.c \
	bn_mp_clear.c \
	bn_mp_exch.c \
	bn_mp_grow.c \
	bn_mp_shrink.c \
	bn_mp_clamp.c \
	bn_mp_zero.c \
	bn_mp_zero_multi.c \
	bn_mp_set.c \
	bn_mp_set_int.c \
	bn_mp_init_size.c \
	bn_mp_copy.c \
	bn_mp_init_copy.c \
	bn_mp_abs.c \
	bn_mp_neg.c \
	bn_mp_cmp_mag.c \
	bn_mp_cmp.c \
	bn_mp_cmp_d.c \
	bn_mp_rshd.c \
	bn_mp_lshd.c \
	bn_mp_mod_2d.c \
	bn_mp_div_2d.c \
	bn_mp_mul_2d.c \
	bn_mp_div_2.c \
	bn_mp_mul_2.c \
	bn_s_mp_add.c \
	bn_s_mp_sub.c \
	bn_fast_s_mp_mul_digs.c \
	bn_s_mp_mul_digs.c \
	bn_fast_s_mp_mul_high_digs.c \
	bn_s_mp_mul_high_digs.c \
	bn_fast_s_mp_sqr.c \
	bn_s_mp_sqr.c \
	bn_mp_add.c \
	bn_mp_sub.c \
	bn_mp_karatsuba_mul.c \
	bn_mp_mul.c \
	bn_mp_karatsuba_sqr.c \
	bn_mp_sqr.c \
	bn_mp_div.c \
	bn_mp_mod.c \
	bn_mp_add_d.c \
	bn_mp_sub_d.c \
	bn_mp_mul_d.c \
	bn_mp_div_d.c \
	bn_mp_mod_d.c \
	bn_mp_expt_d.c \
	bn_mp_addmod.c \
	bn_mp_submod.c \
	bn_mp_mulmod.c \
	bn_mp_sqrmod.c \
	bn_mp_gcd.c \
	bn_mp_lcm.c \
	bn_fast_mp_invmod.c \
	bn_mp_invmod.c \
	bn_mp_reduce.c \
	bn_mp_montgomery_setup.c \
	bn_fast_mp_montgomery_reduce.c \
	bn_mp_montgomery_reduce.c \
	bn_mp_exptmod_fast.c \
	bn_mp_exptmod.c \
	bn_mp_2expt.c \
	bn_mp_n_root.c \
	bn_mp_jacobi.c \
	bn_reverse.c \
	bn_mp_count_bits.c \
	bn_mp_read_unsigned_bin.c \
	bn_mp_read_signed_bin.c \
	bn_mp_to_unsigned_bin.c \
	bn_mp_to_signed_bin.c \
	bn_mp_unsigned_bin_size.c \
	bn_mp_signed_bin_size.c \
	bn_mp_xor.c \
	bn_mp_and.c \
	bn_mp_or.c \
	bn_mp_rand.c \
	bn_mp_montgomery_calc_normalization.c \
	bn_mp_prime_is_divisible.c \
	bn_prime_tab.c \
	bn_mp_prime_fermat.c \
	bn_mp_prime_miller_rabin.c \
	bn_mp_prime_is_prime.c \
	bn_mp_prime_next_prime.c \
	bn_mp_find_prime.c \
	bn_mp_dr_reduce.c \
	bn_mp_dr_is_modulus.c \
	bn_mp_dr_setup.c \
	bn_mp_reduce_setup.c \
	bn_mp_toom_mul.c \
	bn_mp_toom_sqr.c \
	bn_mp_div_3.c \
	bn_s_mp_exptmod.c \
	bn_mp_reduce_2k.c \
	bn_mp_reduce_is_2k.c \
	bn_mp_reduce_2k_setup.c \
	bn_mp_reduce_2k_l.c \
	bn_mp_reduce_is_2k_l.c \
	bn_mp_reduce_2k_setup_l.c \
	bn_mp_radix_smap.c \
	bn_mp_read_radix.c \
	bn_mp_toradix.c \
	bn_mp_radix_size.c \
	bn_mp_fread.c \
	bn_mp_fwrite.c \
	bn_mp_cnt_lsb.c \
	bn_error.c \
	bn_mp_init_multi.c \
	bn_mp_clear_multi.c \
	bn_mp_exteuclid.c \
	bn_mp_toradix_n.c \
	bn_mp_prime_random_ex.c \
	bn_mp_get_int.c \
	bn_mp_sqrt.c \
	bn_mp_is_square.c \
	bn_mp_init_set.c \
	bn_mp_init_set_int.c \
	bn_mp_invmod_slow.c \
	bn_mp_prime_rabin_miller_trials.c \
	bn_mp_to_signed_bin_n.c \
	bn_mp_to_unsigned_bin_n.c

SRCS=	${LTMSOURCES}	\
        aes.c           \
        bn.c            \
        common.c        \
        camellia.c      \
        camellia-ntt.c  \
        des.c           \
        dh.c            \
        dh-ltm.c        \
        dsa.c           \
        doxygen.c       \
        evp.c           \
        evp-hcrypto.c   \
        evp-cc.c        \
        evp-openssl.c   \
        evp-pkcs11.c    \
        engine.c        \
        hmac.c          \
        md4.c           \
        md5.c           \
        pkcs5.c         \
        pkcs12.c        \
        rand-fortuna.c  \
        rand-timer.c    \
        rand-unix.c     \
        rand.c          \
        rc2.c           \
        rc4.c           \
        rijndael-alg-fst.c \
        rnd_keys.c      \
        rsa.c           \
        rsa-gmp.c       \
        rsa-ltm.c       \
        sha.c           \
        sha256.c        \
        sha512.c        \
        validate.c      \
        ui.c            \
        undef.h

CFLAGS+=-I${KRB5DIR}/lib/hx509
CFLAGS+=-I${KRB5DIR}/lib/hx509/ref
CFLAGS+=-I${KRB5DIR}/lib/hcrypto
CFLAGS+=-I${KRB5DIR}/lib/hcrypto/libtommath
CFLAGS+=-I${KRB5DIR}/lib/asn1
CFLAGS+=-I${KRB5DIR}/lib/wind
CFLAGS+=-I${KRB5DIR}/lib/roken
CFLAGS+=-I${KRB5DIR}/lib
CFLAGS+=-I${SRCTOP}/contrib/com_err
CFLAGS+=-I.

.SUFFIXES: .h .c

.include <bsd.lib.mk>

.PATH: ${KRB5DIR}/lib/hcrypto ${KRB5DIR}/lib/hcrypto/libtommath
