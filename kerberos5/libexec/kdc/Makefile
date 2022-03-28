# $FreeBSD$

PACKAGE=	kerberos

PROG=	kdc
MAN=	kdc.8

SRCS=	config.c \
	connect.c \
	announce.c \
	main.c

CFLAGS+=-I${KRB5DIR}/lib/krb5 -I${KRB5DIR}/lib/asn1 -I${KRB5DIR}/lib/roken \
	-I${KRB5DIR}/lib/gssapi \
	-I${KRB5DIR}/kdc -I${KRB5DIR}/include \
	-I${.OBJDIR:H:H}/lib/libhdb \
	-I${SRCTOP}/contrib/com_err ${LDAPCFLAGS}
LIBADD=	kdc hdb hcrypto krb5 roken gssapi_krb5 crypt vers
LDFLAGS=${LDAPLDFLAGS}

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/kdc
