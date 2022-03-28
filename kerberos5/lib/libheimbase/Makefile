#$FreeBSD$

PACKAGE=	kerberos

LIB=	heimbase
LDFLAGS=	-Wl,--no-undefined
LIBADD=	pthread roken
VERSION_MAP= ${KRB5DIR}/lib/base/version-script.map

INCS=	baselocl.h heimbase.h heimbasepriv.h heimqueue.h

SRCS= \
	array.c \
	bool.c \
	bsearch.c \
	data.c \
	db.c \
	dict.c \
	dll.c \
	error.c \
	heimbase.c \
	json.c \
	null.c \
	number.c \
	string.c \
	test_base.c

CFLAGS+=	-I${KRB5DIR}/include

.include <bsd.lib.mk>

.PATH: ${KRB5DIR}/lib/base
