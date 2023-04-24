# $FreeBSD$

PACKAGE=	kerberos-lib

LIB=	gssapi_mech
LDFLAGS= -Wl,-Bsymbolic -Wl,--no-undefined
LIBADD=	gssapi krb5 hcrypto crypto roken asn1 heimbase heimntlm com_err
SHLIB_MAJOR=	10

INCS=	${KRB5DIR}/lib/gssapi/gssapi/gssapi_krb5.h
INCSDIR= ${INCLUDEDIR}/gssapi

SRCS=	8003.c \
	address_to_krb5addr.c \
	arcfour.c \
	authorize_localname.c \
	cfx.c \
	context.c \
	context_stubs.c \
	copy_ccache.c \
	cred_stubs.c \
	crypto.c \
	decapsulate.c \
	doxygen.c \
	encapsulate.c \
	external.c \
	get_mic.c \
	gkrb5_err.c \
	gkrb5_err.h \
	gss_accept_sec_context.c \
	gss_acquire_cred.c \
	gss_acquire_cred_ext.c \
	gss_acquire_cred_with_password.c \
	gss_add_cred.c \
	gss_add_cred_with_password.c \
	gss_add_oid_set_member.c \
	gss_aeap.c \
	gss_authorize_localname.c \
	gss_buffer_set.c \
	gss_canonicalize_name.c \
	gss_compare_name.c \
	gss_context_time.c \
	gss_create_empty_oid_set.c \
	gss_cred.c \
	gss_decapsulate_token.c \
	gss_delete_name_attribute.c \
	gss_delete_sec_context.c \
	gss_display_name.c \
	gss_display_name_ext.c \
	gss_display_status.c \
	gss_duplicate_name.c \
	gss_duplicate_oid.c \
	gss_encapsulate_token.c \
	gss_export_name.c \
	gss_export_name_composite.c \
	gss_export_sec_context.c \
	gss_get_mic.c \
	gss_get_name_attribute.c \
	gss_import_name.c \
	gss_import_sec_context.c \
	gss_indicate_mechs.c \
	gss_init_sec_context.c \
	gss_inquire_context.c \
	gss_inquire_cred.c \
	gss_inquire_cred_by_mech.c \
	gss_inquire_cred_by_oid.c \
	gss_inquire_mechs_for_name.c \
	gss_inquire_name.c \
	gss_inquire_names_for_mech.c \
	gss_inquire_sec_context_by_oid.c \
	gss_krb5.c \
	gss_mech_switch.c \
	gss_mo.c \
	gss_names.c \
	gss_oid.c \
	gss_oid_equal.c \
	gss_oid_to_str.c \
	gss_pname_to_uid.c \
	gss_process_context_token.c \
	gss_pseudo_random.c \
	gss_release_buffer.c \
	gss_release_cred.c \
	gss_release_name.c \
	gss_release_oid.c \
	gss_release_oid_set.c \
	gss_seal.c \
	gss_set_cred_option.c \
	gss_set_name_attribute.c \
	gss_set_sec_context_option.c \
	gss_sign.c \
	gss_store_cred.c \
	gss_test_oid_set_member.c \
	gss_unseal.c \
	gss_unwrap.c \
	gss_utils.c \
	gss_verify.c \
	gss_verify_mic.c \
	gss_wrap.c \
	gss_wrap_size_limit.c \
	inquire_cred.c \
	inquire_cred_by_oid.c \
	init.c \
	init_sec_context.c \
	indicate_mechs.c \
	iter_cred.c \
	kdc.c \
	pname_to_uid.c \
	prf.c \
	release_buffer.c \
	sequence.c \
	set_cred_option.c \
	set_sec_context_option.c \
	store_cred.c \
	unwrap.c \
	verify_mic.c \
	wrap.c \
	${GEN:S/.x$/.c/:S/.hx$/.h/}

#SRCS+=	gss_add_oid_set_member.c \
#	gss_create_empty_oid_set.c \
#	gss_release_buffer.c \
#	gss_release_oid_set.c \
#	gss_test_oid_set_member.c \
#	gss_utils.c

# SRCS+=	${GEN_SPNEGO:S/.x$/.c/:S/.hx$/.h/}
# SRCS+=	${GEN_GSSAPI:S/.x$/.c/:S/.hx$/.h/}
SRCS+=	${GEN_SPNEGO_EXTERNAL}
SRCS+=	${GEN_NTLM_EXTERNAL}
SRCS+=	${GEN_SPNEGO_INIT_SEC_CONTEXT}
SRCS+=	${GEN_NTLM_INIT_SEC_CONTEXT}
SRCS+=	${GEN_SPNEGO_ACCEPT_SEC_CONTEXT}
SRCS+=	${GEN_KRB5_ACCEPT_SEC_CONTEXT}
SRCS+=	${GEN_NTLM_ACCEPT_SEC_CONTEXT}
SRCS+=	${GEN_KRB5_DELETE_SEC_CONTEXT}
SRCS+=	${GEN_NTLM_DELETE_SEC_CONTEXT}
SRCS+=	${GEN_SPNEGO_COMPAT}
SRCS+=	${GEN_KRB5_COMPAT}
SRCS+=	${GEN_NTLM_ACQUIRE_CRED}
SRCS+=	${GEN_KRB5_ACQUIRE_CRED}
SRCS+=	${GEN_NTLM_RELEASE_CRED}
SRCS+=	${GEN_KRB5_RELEASE_CRED}
SRCS+=	${GEN_NTLM_ADD_CRED}
SRCS+=	${GEN_KRB5_ADD_CRED}
SRCS+=	${GEN_NTLM_PROCESS_CONTEXT_TOKEN}
SRCS+=	${GEN_KRB5_PROCESS_CONTEXT_TOKEN}
SRCS+=	${GEN_NTLM_CONTEXT_TIME}
SRCS+=	${GEN_KRB5_CONTEXT_TIME}
SRCS+=	${GEN_NTLM_DISPLAY_STATUS}
SRCS+=	${GEN_KRB5_DISPLAY_STATUS}
SRCS+=	${GEN_NTLM_CANONICALIZE_NAME}
SRCS+=	${GEN_KRB5_CANONICALIZE_NAME}
SRCS+=	${GEN_NTLM_CREDS}
SRCS+=	${GEN_KRB5_CREDS}
SRCS+=	${GEN_NTLM_COMPARE_NAME}
SRCS+=	${GEN_KRB5_COMPARE_NAME}
SRCS+=	${GEN_NTLM_DUPLICATE_NAME}
SRCS+=	${GEN_KRB5_DUPLICATE_NAME}
SRCS+=	${GEN_NTLM_EXPORT_NAME}
SRCS+=	${GEN_KRB5_EXPORT_NAME}
SRCS+=	${GEN_NTLM_IMPORT_NAME}
SRCS+=	${GEN_KRB5_IMPORT_NAME}
SRCS+=	${GEN_NTLM_DISPLAY_NAME}
SRCS+=	${GEN_KRB5_DISPLAY_NAME}
SRCS+=	${GEN_NTLM_EXPORT_SEC_CONTEXT}
SRCS+=	${GEN_KRB5_EXPORT_SEC_CONTEXT}
SRCS+=	${GEN_NTLM_IMPORT_SEC_CONTEXT}
SRCS+=	${GEN_KRB5_IMPORT_SEC_CONTEXT}
SRCS+=	${GEN_NTLM_INQUIRE_CONTEXT}
SRCS+=	${GEN_KRB5_INQUIRE_CONTEXT}
SRCS+=	${GEN_NTLM_INQUIRE_CRED_BY_MECH}
SRCS+=	${GEN_KRB5_INQUIRE_CRED_BY_MECH}
SRCS+=	${GEN_NTLM_INQUIRE_MECHS_FOR_NAME}
SRCS+=	${GEN_KRB5_INQUIRE_MECHS_FOR_NAME}
SRCS+=	${GEN_NTLM_INQUIRE_NAMES_FOR_MECH}
SRCS+=	${GEN_KRB5_INQUIRE_NAMES_FOR_MECH}
SRCS+=	${GEN_NTLM_INQUIRE_SEC_CONTEXT_BY_OID}
SRCS+=	${GEN_KRB5_INQUIRE_SEC_CONTEXT_BY_OID}
SRCS+=	${GEN_NTLM_RELEASE_NAME}
SRCS+=	${GEN_KRB5_RELEASE_NAME}

CFLAGS+=-I${KRB5DIR}/lib/gssapi
CFLAGS+=-I${KRB5DIR}/lib/gssapi/mech
CFLAGS+=-I${KRB5DIR}/lib/gssapi/krb5
CFLAGS+=-I${KRB5DIR}/lib/gssapi/gssapi
CFLAGS+=-I${KRB5DIR}/lib/gssapi/spnego
CFLAGS+=-I${KRB5DIR}/lib/gssapi/ntlm
CFLAGS+=-I${KRB5DIR}/lib/krb5
CFLAGS+=-I${KRB5DIR}/lib/asn1
CFLAGS+=-I${KRB5DIR}/lib/roken
CFLAGS+=-I${KRB5DIR}/lib/base
CFLAGS+=-I${KRB5DIR}/lib
CFLAGS+=-I${SRCTOP}/contrib/com_err
CFLAGS+=-I.

GEN_CONTEXTFLAGS=       asn1_ContextFlags.x
GEN_CONTEXTTOKEN=       asn1_GSSAPIContextToken.x
GEN_MECHTYPE=           asn1_MechType.x
GEN_MECH_TYPELIST=      asn1_MechTypeList.x
GEN_NEGHINTS=           asn1_NegHints.x
GEN_NEGTOKENINT=        asn1_NegTokenInit.x
GEN_TOKENINITWIN=       asn1_NegTokenInitWin.x
GEN_NEG_TOKENRESP=      asn1_NegTokenResp.x
GEN_NEGOTIATIONTOKEN=   asn1_NegotiationToken.x
GEN_NEGOTIATIONTOKENWIN=asn1_NegotiationTokenWin.x

GEN_SPNEGO= \
	spnego_asn1.hx \
	spnego_asn1-priv.hx

GEN_GSSAPI= \
	${GEN_CONTEXTFLAGS} \
	${GEN_CONTEXTTOKEN} \
	${GEN_MECHTYPE} \
	${GEN_MECH_TYPELIST} \
	${GEN_NEGHINTS} \
	${GEN_NEGTOKENINT} \
	${GEN_TOKENINITWIN} \
	${GEN_NEG_TOKENRESP} \
	${GEN_NEGOTIATIONTOKEN} \
	${GEN_NEGOTIATIONTOKENWIN} \
	gssapi_asn1.hx \
	gssapi_asn1-priv.hx

GEN_SPNEGO_EXTERNAL=	spnego_external.c
GEN_NTLM_EXTERNAL=	ntlm_external.c
GEN_SPNEGO_INIT_SEC_CONTEXT=spnego_init_sec_context.c
GEN_NTLM_INIT_SEC_CONTEXT=ntlm_init_sec_context.c
GEN_SPNEGO_ACCEPT_SEC_CONTEXT=spnego_accept_sec_context.c
GEN_KRB5_ACCEPT_SEC_CONTEXT=krb5_accept_sec_context.c
GEN_NTLM_ACCEPT_SEC_CONTEXT=ntlm_accept_sec_context.c
GEN_KRB5_DELETE_SEC_CONTEXT=krb5_delete_sec_context.c
GEN_NTLM_DELETE_SEC_CONTEXT=ntlm_delete_sec_context.c
GEN_SPNEGO_COMPAT=	spnego_compat.c
GEN_KRB5_COMPAT=	krb5_compat.c
GEN_NTLM_ACQUIRE_CRED=	ntlm_acquire_cred.c
GEN_KRB5_ACQUIRE_CRED=	krb5_acquire_cred.c
GEN_NTLM_RELEASE_CRED=	ntlm_release_cred.c
GEN_KRB5_RELEASE_CRED=	krb5_release_cred.c
GEN_NTLM_ADD_CRED=	ntlm_add_cred.c
GEN_KRB5_ADD_CRED=	krb5_add_cred.c
GEN_NTLM_PROCESS_CONTEXT_TOKEN=	ntlm_process_context_token.c
GEN_KRB5_PROCESS_CONTEXT_TOKEN=	krb5_process_context_token.c
GEN_NTLM_CONTEXT_TIME=	ntlm_context_time.c
GEN_KRB5_CONTEXT_TIME=	krb5_context_time.c
GEN_NTLM_DISPLAY_STATUS=	ntlm_display_status.c
GEN_KRB5_DISPLAY_STATUS=	krb5_display_status.c
GEN_NTLM_PROCESS_CONTEXT_TOKEN=	ntlm_process_context_token.c
GEN_KRB5_PROCESS_CONTEXT_TOKEN=	krb5_process_context_token.c
GEN_NTLM_CANONICALIZE_NAME=	ntlm_canonicalize_name.c
GEN_KRB5_CANONICALIZE_NAME=	krb5_canonicalize_name.c

GEN_NTLM_CREDS=	ntlm_creds.c
GEN_KRB5_CREDS=	krb5_creds.c
GEN_NTLM_COMPARE_NAME=	ntlm_compare_name.c
GEN_KRB5_COMPARE_NAME=	krb5_compare_name.c
GEN_NTLM_DUPLICATE_NAME=	ntlm_duplicate_name.c
GEN_KRB5_DUPLICATE_NAME=	krb5_duplicate_name.c
GEN_NTLM_EXPORT_NAME=	ntlm_export_name.c
GEN_KRB5_EXPORT_NAME=	krb5_export_name.c
GEN_NTLM_IMPORT_NAME=	ntlm_import_name.c
GEN_KRB5_IMPORT_NAME=	krb5_import_name.c
GEN_NTLM_DISPLAY_NAME=	ntlm_display_name.c
GEN_KRB5_DISPLAY_NAME=	krb5_display_name.c
GEN_NTLM_EXPORT_SEC_CONTEXT=	ntlm_export_sec_context.c
GEN_KRB5_EXPORT_SEC_CONTEXT=	krb5_export_sec_context.c
GEN_NTLM_IMPORT_SEC_CONTEXT=	ntlm_import_sec_context.c
GEN_KRB5_IMPORT_SEC_CONTEXT=	krb5_import_sec_context.c
GEN_NTLM_INQUIRE_CONTEXT=	ntlm_inquire_context.c
GEN_KRB5_INQUIRE_CONTEXT=	krb5_inquire_context.c
GEN_NTLM_INQUIRE_CRED_BY_MECH=	ntlm_inquire_cred_by_mech.c
GEN_KRB5_INQUIRE_CRED_BY_MECH=	krb5_inquire_cred_by_mech.c
GEN_NTLM_INQUIRE_MECHS_FOR_NAME=	ntlm_inquire_mechs_for_name.c
GEN_KRB5_INQUIRE_MECHS_FOR_NAME=	krb5_inquire_mechs_for_name.c
GEN_NTLM_INQUIRE_NAMES_FOR_MECH=	ntlm_inquire_names_for_mech.c
GEN_KRB5_INQUIRE_NAMES_FOR_MECH=	krb5_inquire_names_for_mech.c
GEN_NTLM_INQUIRE_SEC_CONTEXT_BY_OID=	ntlm_inquire_sec_context_by_oid.c
GEN_KRB5_INQUIRE_SEC_CONTEXT_BY_OID=	krb5_inquire_sec_context_by_oid.c
GEN_NTLM_RELEASE_NAME=	ntlm_release_name.c
GEN_KRB5_RELEASE_NAME=	krb5_release_name.c

GEN+=	${GEN_SPNEGO}
GEN+=	${GEN_GSSAPI}

CLEANFILES= ${GEN} ${GEN:S/.x$/.c/:S/.hx$/.h/} \
	spnego_asn1.[ch]* spnego_asn1-priv.[ch]* \
	gssapi_asn1.[ch]* gssapi_asn1-priv.[ch]*

INCS+=	spnego_asn1.h spnego_asn1-priv.h
INCS+=	gssapi_asn1.h gssapi_asn1-priv.h

.ORDER: ${GEN_SPNEGO}
${GEN_SPNEGO:[2..-1]}: .NOMETA
${GEN_SPNEGO}: spnego.asn1 spnego.opt
	${ASN1_COMPILE} --option-file=${.ALLSRC:M*.opt} \
	${.ALLSRC:M*.asn1} spnego_asn1

${GEN_GSSAPI:[2..-1]}: .NOMETA
${GEN_GSSAPI:[2..-1]}: .NOMETA
${GEN_GSSAPI}: gssapi.asn1
	${ASN1_COMPILE} ${.ALLSRC:M*.asn1} gssapi_asn1

${GEN_SPNEGO_EXTERNAL}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/spnego/external.c ${.TARGET}

${GEN_NTLM_EXTERNAL}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/external.c ${.TARGET}

${GEN_SPNEGO_INIT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/spnego/init_sec_context.c ${.TARGET}

${GEN_NTLM_INIT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/init_sec_context.c ${.TARGET}

${GEN_SPNEGO_ACCEPT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/spnego/accept_sec_context.c ${.TARGET}

${GEN_KRB5_ACCEPT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/accept_sec_context.c ${.TARGET}

${GEN_NTLM_ACCEPT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/accept_sec_context.c ${.TARGET}

${GEN_KRB5_DELETE_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/delete_sec_context.c ${.TARGET}

${GEN_NTLM_DELETE_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/delete_sec_context.c ${.TARGET}

${GEN_SPNEGO_COMPAT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/spnego/compat.c ${.TARGET}

${GEN_KRB5_COMPAT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/compat.c ${.TARGET}

${GEN_NTLM_ACQUIRE_CRED}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/acquire_cred.c ${.TARGET}

${GEN_KRB5_ACQUIRE_CRED}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/acquire_cred.c ${.TARGET}

${GEN_NTLM_RELEASE_CRED}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/release_cred.c ${.TARGET}

${GEN_KRB5_RELEASE_CRED}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/release_cred.c ${.TARGET}

${GEN_NTLM_ADD_CRED}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/add_cred.c ${.TARGET}

${GEN_KRB5_ADD_CRED}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/add_cred.c ${.TARGET}

${GEN_NTLM_PROCESS_CONTEXT_TOKEN}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/process_context_token.c ${.TARGET}

${GEN_KRB5_PROCESS_CONTEXT_TOKEN}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/process_context_token.c ${.TARGET}

${GEN_NTLM_CONTEXT_TIME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/context_time.c ${.TARGET}

${GEN_KRB5_CONTEXT_TIME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/context_time.c ${.TARGET}

${GEN_NTLM_DISPLAY_STATUS}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/display_status.c ${.TARGET}

${GEN_KRB5_DISPLAY_STATUS}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/display_status.c ${.TARGET}

${GEN_NTLM_CANONICALIZE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/canonicalize_name.c ${.TARGET}

${GEN_KRB5_CANONICALIZE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/canonicalize_name.c ${.TARGET}

${GEN_NTLM_CREDS}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/creds.c ${.TARGET}

${GEN_KRB5_CREDS}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/creds.c ${.TARGET}

${GEN_NTLM_COMPARE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/compare_name.c ${.TARGET}

${GEN_KRB5_COMPARE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/compare_name.c ${.TARGET}

${GEN_NTLM_DUPLICATE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/duplicate_name.c ${.TARGET}

${GEN_KRB5_DUPLICATE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/duplicate_name.c ${.TARGET}

${GEN_NTLM_EXPORT_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/export_name.c ${.TARGET}

${GEN_KRB5_EXPORT_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/export_name.c ${.TARGET}

${GEN_NTLM_IMPORT_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/import_name.c ${.TARGET}

${GEN_KRB5_IMPORT_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/import_name.c ${.TARGET}

${GEN_NTLM_DISPLAY_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/display_name.c ${.TARGET}

${GEN_KRB5_DISPLAY_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/display_name.c ${.TARGET}

${GEN_NTLM_EXPORT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/export_sec_context.c ${.TARGET}

${GEN_KRB5_EXPORT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/export_sec_context.c ${.TARGET}

${GEN_NTLM_IMPORT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/import_sec_context.c ${.TARGET}

${GEN_KRB5_IMPORT_SEC_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/import_sec_context.c ${.TARGET}

${GEN_NTLM_INQUIRE_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/inquire_context.c ${.TARGET}

${GEN_KRB5_INQUIRE_CONTEXT}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/inquire_context.c ${.TARGET}

${GEN_NTLM_INQUIRE_CRED_BY_MECH}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/inquire_cred_by_mech.c ${.TARGET}

${GEN_KRB5_INQUIRE_CRED_BY_MECH}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/inquire_cred_by_mech.c ${.TARGET}

${GEN_NTLM_INQUIRE_MECHS_FOR_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/inquire_mechs_for_name.c ${.TARGET}

${GEN_KRB5_INQUIRE_MECHS_FOR_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/inquire_mechs_for_name.c ${.TARGET}

${GEN_NTLM_INQUIRE_NAMES_FOR_MECH}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/inquire_names_for_mech.c ${.TARGET}

${GEN_KRB5_INQUIRE_NAMES_FOR_MECH}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/inquire_names_for_mech.c ${.TARGET}

${GEN_NTLM_INQUIRE_SEC_CONTEXT_BY_OID}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/inquire_sec_context_by_oid.c ${.TARGET}

${GEN_KRB5_INQUIRE_SEC_CONTEXT_BY_OID}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/inquire_sec_context_by_oid.c ${.TARGET}

${GEN_NTLM_RELEASE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/ntlm/release_name.c ${.TARGET}

${GEN_KRB5_RELEASE_NAME}: .NOMETA
	${CP} ${KRB5DIR}/lib/gssapi/krb5/release_name.c ${.TARGET}

.SUFFIXES: .h .c .x .hx

.x.c:
	${CP} ${.IMPSRC} ${.TARGET}

.hx.h:
	${CP} ${.IMPSRC} ${.TARGET}

.include <bsd.lib.mk>

.SUFFIXES: .h .c .x .hx

.PATH: ${KRB5DIR}/lib/gssapi/mech ${KRB5DIR}/lib/gssapi/krb5 ${KRB5DIR}/lib/gssapi/spnego ${KRB5DIR}/lib/gssapi/ntlm ${SRCTOP}/lib/libgssapi
