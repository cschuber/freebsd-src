# $FreeBSD$

PACKAGE=	kerberos

PROG=	kadmind
MAN=	kadmind.8
SRCS=	rpc.c \
	server.c \
	kadmind.c \
	kadm_conn.c

CFLAGS+=-I${KRB5DIR}/lib/krb5 -I${KRB5DIR}/lib/asn1 -I${KRB5DIR}/lib/roken \
	-I${KRB5DIR}/lib/gssapi/gssapi \
	-I${KRB5DIR}/lib/gssapi \
	-I${KRB5DIR}/include \
	-I${.OBJDIR:H:H}/lib/libhdb \
	-I${SRCTOP}/contrib/com_err ${LDAPCFLAGS}
LIBADD=	kadm5srv gssapi_krb5 gssapi hdb krb5 roken vers
DPADD=	${LDAPDPADD}
LDADD=	${LDAPLDADD}
LDFLAGS=${LDAPLDFLAGS}

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/kadmin
