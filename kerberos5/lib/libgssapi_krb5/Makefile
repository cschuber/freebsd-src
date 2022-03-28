# $FreeBSD$

.include "../Makefile.inc"

PACKAGE=	kerberos

LIB=	gssapi_krb5
LDFLAGS= -Wl,-Bsymbolic -Wl,--no-undefined
VERSION_MAP= ${KRB5DIR}/lib/gssapi/version-script.map
LIBADD=	gssapi krb5 crypto hcrypto roken asn1 heimbase heimntlm com_err
SHLIB_MAJOR=	10

INCS=	${KRB5DIR}/lib/gssapi/gssapi/gssapi_krb5.h \
	${KRB5DIR}/lib/gssapi/gssapi/gssapi_oid.h \
	${KRB5DIR}/lib/gssapi/gssapi/gssapi_ntlm.h \
	${KRB5DIR}/lib/gssapi/gssapi/gssapi_spnego.h
INCSDIR= ${INCLUDEDIR}/gssapi

# krb5
SRCS=	8003.c \
	krb5_accept_sec_context.c \
	krb5_acquire_cred.c \
	krb5_add_cred.c \
	address_to_krb5addr.c \
	aeap.c \
	arcfour.c \
	authorize_localname.c \
	krb5_canonicalize_name.c \
	ccache_name.c \
	cfx.c \
	krb5_compare_name.c \
	krb5_compat.c \
	krb5_context_time.c \
	copy_ccache.c \
	krb5_creds.c \
	decapsulate.c \
	krb5_delete_sec_context.c \
	krb5_display_name.c \
	krb5_display_status.c \
	krb5_duplicate_name.c \
	encapsulate.c \
	krb5_export_name.c \
	krb5_export_sec_context.c \
	get_mic.c \
	gkrb5_err.c \
	gkrb5_err.h \
	krb5_import_name.c \
	krb5_import_sec_context.c \
	krb5_indicate_mechs.c \
	init.c \
	krb5_init_sec_context.c \
	krb5_inquire_context.c \
	inquire_cred.c \
	krb5_inquire_cred_by_mech.c \
	inquire_cred_by_oid.c \
	krb5_inquire_mechs_for_name.c \
	krb5_inquire_names_for_mech.c \
	krb5_inquire_sec_context_by_oid.c \
	pname_to_uid.c \
	prf.c \
	krb5_process_context_token.c \
	release_buffer.c \
	krb5_release_cred.c \
	krb5_release_name.c \
	sequence.c \
	set_cred_option.c \
	set_sec_context_option.c \
	store_cred.c \
	ticket_flags.c \
	unwrap.c \
	verify_mic.c \
	wrap.c \
	krb5_external.c \
	gss_krb5.c \
	gss_oid.c

# mech
SRCS+=	context.c \
	doxygen.c \
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
	gss_mech_switch.c \
	gss_mo.c \
	gss_names.c \
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
	spnego_external.c \
	${GEN_M:S/.x$/.c/:S/.hx$/.h/}

# spnego
SRCS+=	spnego_accept_sec_context.c \
	spnego_compat.c \
	context_stubs.c \
	spnego_init_sec_context.c \
	cred_stubs.c \
	${GEN_S:S/.x$/.c/:S/.hx$/.h/}

# NTLM
SRCS+=	ntlm_accept_sec_context.c \
	crypto.c \
	ntlm_delete_sec_context.c \
	ntlm_external.c \
	ntlm_init_sec_context.c \
	iter_cred.c \
	kdc.c \
	ntlm_acquire_cred.c \
	ntlm_release_name.c \
	ntlm_release_cred.c \
	ntlm_process_context_token.c \
	ntlm_context_time.c \
	ntlm_add_cred.c \
	ntlm_canonicalize_name.c \
	ntlm_compare_name.c \
	ntlm_creds.c \
	ntlm_display_name.c \
	ntlm_display_status.c \
	ntlm_duplicate_name.c \
	ntlm_export_name.c \
	ntlm_export_sec_context.c \
	ntlm_import_name.c \
	ntlm_import_sec_context.c \
	ntlm_indicate_mechs.c \
	ntlm_inquire_context.c \
	ntlm_inquire_cred_by_mech.c \
	ntlm_inquire_mechs_for_name.c \
	ntlm_inquire_names_for_mech.c \
	ntlm_inquire_sec_context_by_oid.c

# spnego
GEN_S=	asn1_ContextFlags.x \
	asn1_MechType.x \
	asn1_MechTypeList.x \
	asn1_NegotiationToken.x \
	asn1_NegotiationTokenWin.x \
	asn1_NegHints.x \
	asn1_NegTokenInit.x \
	asn1_NegTokenInitWin.x \
	asn1_NegTokenResp.x \
	spnego_asn1.hx \
	spnego_asn1-priv.hx

# mech
GEN_M=	asn1_GSSAPIContextToken.x \
	gssapi_asn1-template.x \
	gssapi_asn1.hx \
	gssapi_asn1-priv.hx

CFLAGS+=-I${KRB5DIR}/lib/gssapi
CFLAGS+=-I${KRB5DIR}/lib/gssapi/krb5
CFLAGS+=-I${KRB5DIR}/lib/gssapi/mech
CFLAGS+=-I${KRB5DIR}/lib/gssapi/gssapi
CFLAGS+=-I${KRB5DIR}/lib/gssapi/spnego
CFLAGS+=-I${KRB5DIR}/lib/gssapi/ntlm
CFLAGS+=-I${KRB5DIR}/lib/krb5
CFLAGS+=-I${KRB5DIR}/lib/asn1
CFLAGS+=-I${KRB5DIR}/lib/roken
CFLAGS+=-I${KRB5DIR}/include
CFLAGS+=-I${SRCTOP}/contrib/com_err
CFLAGS+=-I.

CLEANFILES=	${GEN_S} ${GEN_S:S/.x$/.c/:S/.hx$/.h/} \
		spnego_export.c \
		krb5_accept_sec_context.c \
		krb5_compat.c \
		gssapi_asn1_files gssapi_asn1-template.c

CLEANFILES+=	${GEN_M} ${GEN_M:S/.x$/.c/:S/.hx$/.h/} \
		mech_export.c \
		spnego_accept_sec_context.c \
		spnego_compat.c \
		spnego_asn1_files spnego_asn1-template.c

CLEANFILES+=	ntlm_external.c \
		spnego_external.c \
		krb5_external.c \
		ntlm_accept_sec_context.c \
		spnego_accept_sec_context.c \
		krb5_accept_sec_context.c \
		ntlm_delete_sec_context.c \
		krb5_delete_sec_context.c \
		spnego_compat.c \
		krb5_compat.c \
		ntlm_init_sec_context.c \
		spnego_init_sec_context.c \
		krb5_init_sec_context.c \
		krb5_release_name.c \
		ntlm_release_name.c \
		krb5_acquire_cred.c \
		ntlm_acquire_cred.c \
		krb5_release_cred.c \
		ntlm_release_cred.c \
		ntlm_release_cred.c \
		krb5_release_cred.c \
		ntlm_process_context_token.c \
		krb5_process_context_token.c \
		ntlm_context_time.c \
		krb5_context_time.c \
		krb5_add_cred.c \
		ntlm_add_cred.c \
		ntlm_canonicalize_name.c \
		krb5_canonicalize_name.c \
		ntlm_compare_name.c \
		krb5_compare_name.c \
		ntlm_creds.c  \
		krb5_creds.c \
		ntlm_display_name.c \
		krb5_display_name.c \
		ntlm_display_status.c \
		krb5_display_status.c \
		ntlm_duplicate_name.c \
		krb5_duplicate_name.c \
		ntlm_ export_name.c \
		krb5_export_name.c \
		ntlm_export_sec_context.c \
		krb5_export_sec_context.c \
		ntlm_import_name.c \
		krb5_import_name.c \
		ntlm_import_sec_context.c \
		krb5_import_sec_context.c \
		ntlm_indicate_mechs.c \
		krb5_indicate_mechs.c \
		ntlm_inquire_context.c \
		krb5_inquire_context.c \
		ntlm_inquire_cred_by_mech.c \
		krb5_inquire_cred_by_mech.c \
		ntlm_inquire_mechs_for_name.c \
		krb5_inquire_mechs_for_name.c \
		ntlm_inquire_names_for_mech.c \
		krb5_inquire_names_for_mech.c \
		ntlm_inquire_sec_context_by_oid.c \
		krb5_inquire_sec_context_by_oid.c

# spnego
.ORDER: ${GEN_S}
${GEN_S:[2..-1]}: .NOMETA
${GEN_S}: spnego.asn1 spnego.opt
	${ASN1_COMPILE} --option-file=${.ALLSRC:M*.opt} \
		${.ALLSRC:M*.asn1} spnego_asn1

# mech
.ORDER: ${GEN_M}
${GEN_M:[2..-1]}: .NOMETA
${GEN_M}: gssapi.asn1
	${ASN1_COMPILE} \
		${.ALLSRC:M*.asn1} gssapi_asn1

.SUFFIXES: .h .c .x .hx

.x.c:
	${CP} ${.IMPSRC} ${.TARGET}

.hx.h:
	${CP} ${.IMPSRC} ${.TARGET}

ntlm_external.c:	${KRB5DIR}/lib/gssapi/ntlm/external.c
	${CP} ${.ALLSRC} ${.TARGET}

spnego_external.c:	${KRB5DIR}/lib/gssapi/spnego/external.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_external.c:	${KRB5DIR}/lib/gssapi/krb5/external.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_init_sec_context.c:	${KRB5DIR}/lib/gssapi/ntlm/init_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

spnego_init_sec_context.c:	${KRB5DIR}/lib/gssapi/spnego/init_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_init_sec_context.c:	${KRB5DIR}/lib/gssapi/krb5/init_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_accept_sec_context.c:	${KRB5DIR}/lib/gssapi/ntlm/accept_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

spnego_accept_sec_context.c:	${KRB5DIR}/lib/gssapi/spnego/accept_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_accept_sec_context.c:	${KRB5DIR}/lib/gssapi/krb5/accept_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_delete_sec_context.c:	${KRB5DIR}/lib/gssapi/ntlm/delete_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_delete_sec_context.c:	${KRB5DIR}/lib/gssapi/krb5/delete_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

spnego_compat.c:	${KRB5DIR}/lib/gssapi/spnego/compat.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_compat.c:		${KRB5DIR}/lib/gssapi/krb5/compat.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_release_name.c:	${KRB5DIR}/lib/gssapi/ntlm/release_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_release_name.c:		${KRB5DIR}/lib/gssapi/krb5/release_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_acquire_cred.c:	${KRB5DIR}/lib/gssapi/ntlm/acquire_cred.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_acquire_cred.c:		${KRB5DIR}/lib/gssapi/krb5/acquire_cred.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_release_cred.c:	${KRB5DIR}/lib/gssapi/ntlm/release_cred.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_release_cred.c:		${KRB5DIR}/lib/gssapi/krb5/release_cred.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_process_context_token.c:	${KRB5DIR}/lib/gssapi/ntlm/process_context_token.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_process_context_token.c:		${KRB5DIR}/lib/gssapi/krb5/process_context_token.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_context_time.c:	${KRB5DIR}/lib/gssapi/ntlm/context_time.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_context_time.c:		${KRB5DIR}/lib/gssapi/krb5/context_time.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_add_cred.c:	${KRB5DIR}/lib/gssapi/ntlm/add_cred.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_add_cred.c:		${KRB5DIR}/lib/gssapi/krb5/add_cred.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_canonicalize_name.c:	${KRB5DIR}/lib/gssapi/ntlm/canonicalize_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_canonicalize_name.c:	${KRB5DIR}/lib/gssapi/krb5/canonicalize_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_compare_name.c:	${KRB5DIR}/lib/gssapi/ntlm/compare_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_compare_name.c:	${KRB5DIR}/lib/gssapi/krb5/compare_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_creds.c:		${KRB5DIR}/lib/gssapi/ntlm/creds.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_creds.c:		${KRB5DIR}/lib/gssapi/krb5/creds.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_display_name.c:	${KRB5DIR}/lib/gssapi/ntlm/display_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_display_name.c:	${KRB5DIR}/lib/gssapi/krb5/display_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_display_status.c:	${KRB5DIR}/lib/gssapi/ntlm/display_status.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_display_status.c:	${KRB5DIR}/lib/gssapi/krb5/display_status.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_duplicate_name.c:	${KRB5DIR}/lib/gssapi/ntlm/duplicate_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_duplicate_name.c:	${KRB5DIR}/lib/gssapi/krb5/duplicate_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_export_name.c:	${KRB5DIR}/lib/gssapi/ntlm/export_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_export_name.c:	${KRB5DIR}/lib/gssapi/krb5/export_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_export_sec_context.c:	${KRB5DIR}/lib/gssapi/ntlm/export_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_export_sec_context.c:	${KRB5DIR}/lib/gssapi/krb5/export_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_import_name.c:		${KRB5DIR}/lib/gssapi/ntlm/import_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_import_name.c:		${KRB5DIR}/lib/gssapi/krb5/import_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_import_sec_context.c:	${KRB5DIR}/lib/gssapi/ntlm/import_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_import_sec_context.c:	${KRB5DIR}/lib/gssapi/krb5/import_sec_context.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_indicate_mechs.c:		${KRB5DIR}/lib/gssapi/ntlm/indicate_mechs.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_indicate_mechs.c:		${KRB5DIR}/lib/gssapi/krb5/indicate_mechs.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_inquire_context.c:		${KRB5DIR}/lib/gssapi/ntlm/inquire_context.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_inquire_context.c:		${KRB5DIR}/lib/gssapi/krb5/inquire_context.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_inquire_cred_by_mech.c:	${KRB5DIR}/lib/gssapi/ntlm/inquire_cred_by_mech.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_inquire_cred_by_mech.c:	${KRB5DIR}/lib/gssapi/krb5/inquire_cred_by_mech.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_inquire_mechs_for_name.c:	${KRB5DIR}/lib/gssapi/ntlm/inquire_mechs_for_name.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_inquire_mechs_for_name.c:	${KRB5DIR}/lib/gssapi/krb5/inquire_mechs_for_name.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_inquire_names_for_mech.c:	${KRB5DIR}/lib/gssapi/ntlm/inquire_names_for_mech.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_inquire_names_for_mech.c:	${KRB5DIR}/lib/gssapi/krb5/inquire_names_for_mech.c
	${CP} ${.ALLSRC} ${.TARGET}

ntlm_inquire_sec_context_by_oid.c:	${KRB5DIR}/lib/gssapi/ntlm/inquire_sec_context_by_oid.c
	${CP} ${.ALLSRC} ${.TARGET}

krb5_inquire_sec_context_by_oid.c:	${KRB5DIR}/lib/gssapi/krb5/inquire_sec_context_by_oid.c
	${CP} ${.ALLSRC} ${.TARGET}

.include <bsd.lib.mk>

.SUFFIXES: .h .c .x .hx

.PATH: ${KRB5DIR}/lib/gssapi/krb5 ${KRB5DIR}/lib/gssapi/mech ${KRB5DIR}/lib/gssapi/spnego ${KRB5DIR}/lib/gssapi/ntlm ${SRCTOP}/lib/libgssapi
