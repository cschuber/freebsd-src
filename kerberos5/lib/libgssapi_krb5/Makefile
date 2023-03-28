# $FreeBSD$

PACKAGE=	kerberos-lib

LIB=	gssapi_krb5
LDFLAGS= -Wl,-Bsymbolic -Wl,--no-undefined
LIBADD=	gssapi krb5 gssapi_mech hcrypto crypto roken asn1 heimbase com_err
SHLIB_MAJOR=	10

INCS=	${KRB5DIR}/lib/gssapi/gssapi/gssapi_krb5.h
INCSDIR= ${INCLUDEDIR}/gssapi

SRCS=	8003.c \
	accept_sec_context.c \
	acquire_cred.c \
	add_cred.c \
	address_to_krb5addr.c \
	aeap.c \
	arcfour.c \
	authorize_localname.c \
	canonicalize_name.c \
	ccache_name.c \
	cfx.c \
	compare_name.c \
	compat.c \
	context_time.c \
	copy_ccache.c \
	creds.c \
	decapsulate.c \
	delete_sec_context.c \
	display_name.c \
	display_status.c \
	duplicate_name.c \
	encapsulate.c \
	export_name.c \
	export_sec_context.c \
	external.c \
	get_mic.c \
	gkrb5_err.c \
	gkrb5_err.h \
	import_name.c \
	import_sec_context.c \
	indicate_mechs.c \
	init.c \
	init_sec_context.c \
	inquire_context.c \
	inquire_cred.c \
	inquire_cred_by_mech.c \
	inquire_cred_by_oid.c \
	inquire_mechs_for_name.c \
	inquire_names_for_mech.c \
	inquire_sec_context_by_oid.c \
	pname_to_uid.c \
	prefix.c \
	prf.c \
	process_context_token.c \
	release_buffer.c \
	release_cred.c \
	release_name.c \
	sequence.c \
	set_cred_option.c \
	set_sec_context_option.c \
	store_cred.c \
	ticket_flags.c \
	unwrap.c \
	verify_mic.c \
	wrap.c \
	gss_krb5.c \
	gss_oid.c \

#SRCS+=	gss_add_oid_set_member.c \
#	gss_create_empty_oid_set.c \
#	gss_release_buffer.c \
#	gss_release_oid_set.c \
#	gss_test_oid_set_member.c \
#	gss_utils.c

SRCS+=	${GEN_SPNEGO:S/.x$/.c/:S/.hx$/.h/} \
	${GEN_GSSAPI:S/.x$/.c/:S/.hx$/.h/}

CFLAGS+=-I${KRB5DIR}/lib/gssapi
CFLAGS+=-I${KRB5DIR}/lib/gssapi/krb5
CFLAGS+=-I${KRB5DIR}/lib/gssapi/gssapi
CFLAGS+=-I${KRB5DIR}/lib/gssapi/mech
CFLAGS+=-I${KRB5DIR}/lib/krb5
CFLAGS+=-I${KRB5DIR}/lib/asn1
CFLAGS+=-I${KRB5DIR}/lib/roken
CFLAGS+=-I${KRB5DIR}/lib/base
CFLAGS+=-I${KRB5DIR}/lib
CFLAGS+=-I${SRCTOP}/contrib/com_err
CFLAGS+=-I.
CFLAGS+=-DOPENSSL_API_COMPAT=0x10100000L

GEN_CONTEXTFLAGS=	asn1_ContextFlags.x
GEN_CONTEXTTOKEN=	asn1_GSSAPIContextToken.x
GEN_MECHTYPE=		asn1_MechType.x
GEN_MECH_TYPELIST=	asn1_MechTypeList.x
GEN_NEGHINTS=		asn1_NegHints.x
GEN_NEGTOKENINT=	asn1_NegTokenInit.x
GEN_TOKENINITWIN=	asn1_NegTokenInitWin.x
GEN_NEG_TOKENRESP=	asn1_NegTokenResp.x
GEN_NEGOTIATIONTOKEN=	asn1_NegotiationToken.x
GEN_NEGOTIATIONTOKENWIN=asn1_NegotiationTokenWin.x

GEN_SPNEGO= \
	${GEN_CONTEXTFLAGS} \
	${GEN_MECHTYPE} \
	${GEN_MECH_TYPELIST} \
	${GEN_NEGHINTS} \
	${GEN_NEGTOKENINT} \
	${GEN_TOKENINITWIN} \
	${GEN_NEG_TOKENRESP} \
	${GEN_NEGOTIATIONTOKEN} \
	${GEN_NEGOTIATIONTOKENWIN} \
	spnego_asn1-priv.hx \
	spnego_asn1-template.x \
	spnego_asn1.hx

GEN_GSSAPI= \
	${GEN_CONTEXTTOKEN} \
	gssapi_asn1-priv.hx \
	gssapi_asn1-template.x \
	gssapi_asn1.hx

GEN+=	${GEN_SPNEGO}
GEN+=	${GEN_GSSAPI}

CLEANFILES= ${GEN} ${GEN:S/.x$/.c/:S/.hx$/.h/} \
	spnego_asn1.[ch]* spnego_asn1-priv.[ch]* \
	gssapi_asn1.[ch]* gssapi_asn1-priv.[ch]*

INCS+=	spnego_asn1.h spnego_asn1-priv.h gssapi_asn1.h gssapi_asn1-priv.h

.ORDER: ${GEN_SPNEGO}
${GEN_SPNEGO:[2..-1]}: .NOMETA
${GEN_SPNEGO}: spnego.asn1 spnego.opt
	${ASN1_COMPILE} --option-file=${.ALLSRC:M*.opt} \
	${.ALLSRC:M*.asn1} spnego_asn1

${GEN_GSSAPI:[2..-1]}: .NOMETA
${GEN_GSSAPI:[2..-1]}: .NOMETA
${GEN_GSSAPI}: gssapi.asn1
	${ASN1_COMPILE} ${.ALLSRC:M*.asn1} gssapi_asn1

.SUFFIXES: .h .c .x .hx

.x.c:
	${CP} ${.IMPSRC} ${.TARGET}

.hx.h:
	${CP} ${.IMPSRC} ${.TARGET}

.include <bsd.lib.mk>

.SUFFIXES: .h .c .x .hx

.PATH: ${KRB5DIR}/lib/gssapi/krb5 ${KRB5DIR}/lib/gssapi/mech ${KRB5DIR}/lib/gssapi/spnego ${SRCTOP}/lib/libgssapi
