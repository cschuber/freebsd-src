# $FreeBSD$

PACKAGE=	kerberos-lib

LIB=	roken
LIBADD=	crypt
VERSION_MAP=	${KRB5DIR}/lib/roken/version-script.map
INCS=	roken.h \
	roken-common.h \
	base32.h \
	base64.h \
	getarg.h \
	getauxval.h \
	hex.h \
	parse_bytes.h \
	parse_time.h \
	parse_units.h \
	resolve.h \
	rtbl.h \
	socket_wrapper.h \
	xdbm.h

SRCS=	base32.c \
	base64.c \
	bswap.c \
	closefrom.c \
	concat.c \
	copyhostent.c \
	cloexec.c \
	clz.c \
	ct.c \
	detach.c \
	doxygen.c \
	dumpdata.c \
	environment.c \
	eread.c \
	esetenv.c \
	ewrite.c \
	getaddrinfo_hostspec.c \
	mkdtemp.c \
	mkostemp.c \
	get_window_size.c \
	getarg.c \
	getauxval.c \
	getnameinfo_verified.c \
	getprogname.c \
	h_errno.c \
	hex.c \
	hostent_find_fqdn.c \
	issuid.c \
	ftello.c \
	mergesort_r.c \
	mini_inetd.c \
	mkdir.c \
	net_read.c \
	net_write.c \
	parse_bytes.c \
	parse_time.c \
	parse_units.c \
	qsort.c \
	rand.c \
	realloc.c \
	resolve.c \
	roken_gethostby.c \
	rtbl.c \
	setprogname.c \
	signal.c \
	simple_exec.c \
	snprintf.c \
	socket.c \
	socket_wrapper.c \
	strcollect.c \
	strerror_r.c \
	strpool.c \
	timeval.c \
	tm2time.c \
	unvis.c \
	fseeko.c \
	vis.c \
	warnerr.c \
	write_pid.c \
	xfree.c \
	${DIST_COMMON} \
	${GEN:S/.hin$/.h/}

DIST_COMMON= \
	ecalloc.c \
	emalloc.c \
	erealloc.c \
	estrdup.c \
	strlwr.c \
	strsep_copy.c \
	strupr.c

GEN=	make_roken.c \
	roken.h

CFLAGS+=-I${KRB5DIR}/lib/roken -I.

CLEANFILES= roken.h \
	make_roken.c \
	${GEN:S/.hin$/.h/}

roken.h: ${MAKE_ROKEN}
	${MAKE_ROKEN} > ${.TARGET}

make_roken.c: roken.h.in roken.awk
	awk -f ${KRB5DIR}/lib/roken/roken.awk ${KRB5DIR}/lib/roken/roken.h.in > make_roken.c

.include <bsd.lib.mk>

.PATH: ${KRB5DIR}/lib/roken
