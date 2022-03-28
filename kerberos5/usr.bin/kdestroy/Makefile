# $FreeBSD$

PACKAGE=	kerberos

PROG=	kdestroy
CFLAGS+=-I${KRB5DIR}/lib/roken \
	-I${KRB5DIR}/include
LIBADD=	kafs5 krb5 roken vers
MAN=	kdestroy.1

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/kuser
