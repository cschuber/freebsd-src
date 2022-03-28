# $FreeBSD$

PACKAGE=	kerberos

PROG=	heimtools
MAN=	klist.1 kswitch.1
LINKS=	${BINDIR}/heimtools ${BINDIR}/klist \
	${BINDIR}/heimtools ${BINDIR}/kswitch
CFLAGS+=	-I${KRB5DIR}/lib/hx509 \
		-I${KRB5DIR}/lib/asn1 \
		-I${KRB5DIR}/lib/roken \
		-I${KRB5DIR}/lib/sl \
		-I${KRB5DIR}/include \
		-I.
LIBADD=	krb5 roken asn1 kafs5 edit sl vers
SRCS=	heimtools.c \
	heimtools-commands.c \
	heimtools-commands.h \
	klist.c \
	kswitch.c \
	copy_cred_cache.c

CLEANFILES=	heimtools-commands.h heimtools-commands.c

heimtools-commands.h: heimtools-commands.in
	${SLC} ${.ALLSRC:M*.in}

heimtools-commands.c: heimtools-commands.h

.include <bsd.prog.mk>

.PATH: ${KRB5DIR}/kuser
