#$FreeBSD$

PACKAGE=	kerberos-lib

LIB=	heimbase
LDFLAGS=	-Wl,--no-undefined
LIBADD=	pthread roken
VERSION_MAP= ${KRB5DIR}/lib/base/version-script.map

INCS=	heimbase.h

SRCS= \
	array.c \
	bool.c \
	bsearch.c \
	data.c \
	db.c \
	dict.c \
	error.c \
	heimbase.c \
	json.c \
	null.c \
	number.c \
	string.c

CFLAGS+=	-I${KRB5DIR}/include \
		-I${KRB5DIR}/lib/base

.include <bsd.lib.mk>

.PATH: ${KRB5DIR}/lib/base
