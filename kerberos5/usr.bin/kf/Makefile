# $FreeBSD$

PACKAGE=	kerberos

PROG=	kf
MAN=	kf.1
CFLAGS+=	-I${KRB5DIR}/lib/asn1 \
		-I${KRB5DIR}/lib/roken \
		-I${KRB5DIR}/lib
LIBADD=	krb5 roken vers

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/appl/kf
