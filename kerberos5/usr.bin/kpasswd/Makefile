# $FreeBSD$

PACKAGE=	kerberos

PROG=	kpasswd
CFLAGS+=-I${KRB5DIR}/lib/roken
LIBADD=	hdb krb5 roken vers hcrypto crypto
LDFLAGS=${LDAPLDFLAGS}

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/kpasswd
