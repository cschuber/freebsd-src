# $FreeBSD$

.include <src.opts.mk>

SUBDIR=	libroken libheimbase libasn1 libhcrypto libwind .WAIT libhdb \
	libheimntlm libhx509 libkadm5clnt libkadm5srv libkrb5 \
	libsl libvers libkdc libheimipcc libheimipcs

SUBDIR+= libkafs5  # requires krb_err.h from libkrb5
SUBDIR_DEPEND_libkafs5=	libkrb5

.if ${MK_GSSAPI} != "no"
SUBDIR+=	libgssapi_krb5
.endif

.include <bsd.subdir.mk>
