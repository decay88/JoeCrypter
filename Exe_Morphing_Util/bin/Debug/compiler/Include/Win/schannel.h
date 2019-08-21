#ifndef _SCHANNEL_H
#define _SCHANNEL_H

#if __POCC__ >= 500
#pragma once
#endif

/* SCHANNEL Security Provider definitions */

#if defined(WIN32_DEFAULT_LIBS) && !defined(_WIN64)
#pragma comment(lib, "schannel.lib")
#endif

#include <wincrypt.h>

#define UNISP_NAME_A  "Microsoft Unified Security Protocol Provider"
#define UNISP_NAME_W  L"Microsoft Unified Security Protocol Provider"
#define SSL2SP_NAME_A  "Microsoft SSL 2.0"
#define SSL2SP_NAME_W  L"Microsoft SSL 2.0"
#define SSL3SP_NAME_A  "Microsoft SSL 3.0"
#define SSL3SP_NAME_W  L"Microsoft SSL 3.0"
#define TLS1SP_NAME_A  "Microsoft TLS 1.0"
#define TLS1SP_NAME_W  L"Microsoft TLS 1.0"
#define PCT1SP_NAME_A  "Microsoft PCT 1.0"
#define PCT1SP_NAME_W  L"Microsoft PCT 1.0"

#define UNISP_RPC_ID  14

#define SECPKG_ATTR_ISSUER_LIST  0x50
#define SECPKG_ATTR_REMOTE_CRED  0x51
#define SECPKG_ATTR_LOCAL_CRED  0x52
#define SECPKG_ATTR_REMOTE_CERT_CONTEXT  0x53
#define SECPKG_ATTR_LOCAL_CERT_CONTEXT  0x54
#define SECPKG_ATTR_ROOT_STORE  0x55
#define SECPKG_ATTR_SUPPORTED_ALGS  0x56
#define SECPKG_ATTR_CIPHER_STRENGTHS  0x57
#define SECPKG_ATTR_SUPPORTED_PROTOCOLS  0x58
#define SECPKG_ATTR_ISSUER_LIST_EX  0x59
#define SECPKG_ATTR_CONNECTION_INFO  0x5a
#define SECPKG_ATTR_EAP_KEY_BLOCK  0x5b
#define SECPKG_ATTR_MAPPED_CRED_ATTR  0x5c
#define SECPKG_ATTR_CACHE_INFO_ATTR  0x5d

#define RCRED_STATUS_NOCRED  0x00000000
#define RCRED_CRED_EXISTS  0x00000001
#define RCRED_STATUS_UNKNOWN_ISSUER  0x00000002

#define LCRED_STATUS_NOCRED  0x00000000
#define LCRED_CRED_EXISTS  0x00000001
#define LCRED_STATUS_UNKNOWN_ISSUER  0x00000002

#define SCH_CRED_V1  0x00000001
#define SCH_CRED_V2  0x00000002
#define SCH_CRED_VERSION  0x00000002
#define SCH_CRED_V3  0x00000003
#define SCHANNEL_CRED_VERSION  0x00000004

#define SCH_CRED_NO_SYSTEM_MAPPER  0x00000002
#define SCH_CRED_NO_SERVERNAME_CHECK  0x00000004
#define SCH_CRED_MANUAL_CRED_VALIDATION  0x00000008
#define SCH_CRED_NO_DEFAULT_CREDS  0x00000010
#define SCH_CRED_AUTO_CRED_VALIDATION  0x00000020
#define SCH_CRED_USE_DEFAULT_CREDS  0x00000040

#define SCH_CRED_REVOCATION_CHECK_END_CERT  0x00000100
#define SCH_CRED_REVOCATION_CHECK_CHAIN  0x00000200
#define SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT 0x00000400
#define SCH_CRED_IGNORE_NO_REVOCATION_CHECK  0x00000800
#define SCH_CRED_IGNORE_REVOCATION_OFFLINE  0x00001000

#define SCHANNEL_RENEGOTIATE  0
#define SCHANNEL_SHUTDOWN  1
#define SCHANNEL_ALERT  2

#define TLS1_ALERT_WARNING  1
#define TLS1_ALERT_FATAL  2

#define TLS1_ALERT_CLOSE_NOTIFY  0
#define TLS1_ALERT_UNEXPECTED_MESSAGE  10
#define TLS1_ALERT_BAD_RECORD_MAC  20
#define TLS1_ALERT_DECRYPTION_FAILED  21
#define TLS1_ALERT_RECORD_OVERFLOW  22
#define TLS1_ALERT_DECOMPRESSION_FAIL  30
#define TLS1_ALERT_HANDSHAKE_FAILURE  40
#define TLS1_ALERT_BAD_CERTIFICATE  42
#define TLS1_ALERT_UNSUPPORTED_CERT  43
#define TLS1_ALERT_CERTIFICATE_REVOKED  44
#define TLS1_ALERT_CERTIFICATE_EXPIRED  45
#define TLS1_ALERT_CERTIFICATE_UNKNOWN  46
#define TLS1_ALERT_ILLEGAL_PARAMETER  47
#define TLS1_ALERT_UNKNOWN_CA  48
#define TLS1_ALERT_ACCESS_DENIED  49
#define TLS1_ALERT_DECODE_ERROR  50
#define TLS1_ALERT_DECRYPT_ERROR  51
#define TLS1_ALERT_EXPORT_RESTRICTION  60
#define TLS1_ALERT_PROTOCOL_VERSION  70
#define TLS1_ALERT_INSUFFIENT_SECURITY  71
#define TLS1_ALERT_INTERNAL_ERROR  80
#define TLS1_ALERT_USER_CANCELED  90
#define TLS1_ALERT_NO_RENEGOTIATATION  100

#define CERT_SCHANNEL_IIS_PRIVATE_KEY_PROP_ID  (CERT_FIRST_USER_PROP_ID+0)
#define CERT_SCHANNEL_IIS_PASSWORD_PROP_ID  (CERT_FIRST_USER_PROP_ID+1)

#define CERT_SCHANNEL_SGC_CERTIFICATE_PROP_ID  (CERT_FIRST_USER_PROP_ID+2)

#define SP_PROT_PCT1_SERVER  0x00000001
#define SP_PROT_PCT1_CLIENT  0x00000002
#define SP_PROT_PCT1  (SP_PROT_PCT1_SERVER|SP_PROT_PCT1_CLIENT)

#define SP_PROT_SSL2_SERVER  0x00000004
#define SP_PROT_SSL2_CLIENT  0x00000008
#define SP_PROT_SSL2  (SP_PROT_SSL2_SERVER|SP_PROT_SSL2_CLIENT)

#define SP_PROT_SSL3_SERVER  0x00000010
#define SP_PROT_SSL3_CLIENT  0x00000020
#define SP_PROT_SSL3  (SP_PROT_SSL3_SERVER|SP_PROT_SSL3_CLIENT)

#define SP_PROT_TLS1_SERVER  0x00000040
#define SP_PROT_TLS1_CLIENT  0x00000080
#define SP_PROT_TLS1  (SP_PROT_TLS1_SERVER|SP_PROT_TLS1_CLIENT)

#define SP_PROT_SSL3TLS1_CLIENTS  (SP_PROT_TLS1_CLIENT|SP_PROT_SSL3_CLIENT)
#define SP_PROT_SSL3TLS1_SERVERS  (SP_PROT_TLS1_SERVER|SP_PROT_SSL3_SERVER)
#define SP_PROT_SSL3TLS1  (SP_PROT_SSL3|SP_PROT_TLS1)

#define SP_PROT_UNI_SERVER  0x40000000
#define SP_PROT_UNI_CLIENT  0x80000000
#define SP_PROT_UNI  (SP_PROT_UNI_SERVER|SP_PROT_UNI_CLIENT)

#define SP_PROT_ALL  0xffffffff
#define SP_PROT_NONE  0
#define SP_PROT_CLIENTS  (SP_PROT_PCT1_CLIENT|SP_PROT_SSL2_CLIENT|SP_PROT_SSL3_CLIENT|SP_PROT_UNI_CLIENT|SP_PROT_TLS1_CLIENT)
#define SP_PROT_SERVERS  (SP_PROT_PCT1_SERVER|SP_PROT_SSL2_SERVER|SP_PROT_SSL3_SERVER|SP_PROT_UNI_SERVER|SP_PROT_TLS1_SERVER)

#define SSLOLD_NAME_A  "Microsoft SSL"
#define SSLOLD_NAME_W  L"Microsoft SSL"
#define PCTOLD_NAME_A  "Microsoft PCT"
#define PCTOLD_NAME_W  L"Microsoft PCT"

#define NETWORK_DREP  0x00000000

#define SCHANNEL_SECRET_TYPE_CAPI  0x00000001
#define SCHANNEL_SECRET_PRIVKEY  0x00000002
#define SCH_CRED_X509_CERTCHAIN  0x00000001
#define SCH_CRED_X509_CAPI  0x00000002
#define SCH_CRED_CERT_CONTEXT  0x00000003

#define SSL_CRACK_CERTIFICATE_NAME  TEXT("SslCrackCertificate")
#define SSL_FREE_CERTIFICATE_NAME  TEXT("SslFreeCertificate")

typedef struct _SecPkgContext_IssuerListInfo {
    DWORD cbIssuerList;
    PBYTE pIssuerList;
} SecPkgContext_IssuerListInfo, *PSecPkgContext_IssuerListInfo;

typedef struct _SecPkgContext_RemoteCredentialInfo {
    DWORD cbCertificateChain;
    PBYTE pbCertificateChain;
    DWORD cCertificates;
    DWORD fFlags;
    DWORD dwBits;
} SecPkgContext_RemoteCredentialInfo, *PSecPkgContext_RemoteCredentialInfo;

typedef SecPkgContext_RemoteCredentialInfo SecPkgContext_RemoteCredenitalInfo, *PSecPkgContext_RemoteCredenitalInfo;

typedef struct _SecPkgContext_LocalCredentialInfo {
    DWORD cbCertificateChain;
    PBYTE pbCertificateChain;
    DWORD cCertificates;
    DWORD fFlags;
    DWORD dwBits;
} SecPkgContext_LocalCredentialInfo, *PSecPkgContext_LocalCredentialInfo;

typedef SecPkgContext_LocalCredentialInfo SecPkgContext_LocalCredenitalInfo, *PSecPkgContext_LocalCredenitalInfo;

typedef struct _SecPkgCred_SupportedAlgs {
    DWORD cSupportedAlgs;
    ALG_ID *palgSupportedAlgs;
} SecPkgCred_SupportedAlgs, *PSecPkgCred_SupportedAlgs;

typedef struct _SecPkgCred_CipherStrengths {
    DWORD dwMinimumCipherStrength;
    DWORD dwMaximumCipherStrength;
} SecPkgCred_CipherStrengths, *PSecPkgCred_CipherStrengths;

typedef struct _SecPkgCred_SupportedProtocols {
    DWORD grbitProtocol;
} SecPkgCred_SupportedProtocols, *PSecPkgCred_SupportedProtocols;

typedef struct _SecPkgContext_IssuerListInfoEx {
    PCERT_NAME_BLOB aIssuers;
    DWORD cIssuers;
} SecPkgContext_IssuerListInfoEx, *PSecPkgContext_IssuerListInfoEx;

typedef struct _SecPkgContext_ConnectionInfo {
    DWORD dwProtocol;
    ALG_ID aiCipher;
    DWORD dwCipherStrength;
    ALG_ID aiHash;
    DWORD dwHashStrength;
    ALG_ID aiExch;
    DWORD dwExchStrength;
} SecPkgContext_ConnectionInfo, *PSecPkgContext_ConnectionInfo;

typedef struct _SecPkgContext_EapKeyBlock {
    BYTE rgbKeys[128];
    BYTE rgbIVs[64];
} SecPkgContext_EapKeyBlock, *PSecPkgContext_EapKeyBlock;

typedef struct _SecPkgContext_MappedCredAttr {
    DWORD dwAttribute;
    PVOID pvBuffer;
} SecPkgContext_MappedCredAttr, *PSecPkgContext_MappedCredAttr;

typedef struct _SecPkgCred_CacheInfo {
    DWORD cbBytesCommitted;
    DWORD cMaxCacheEntries;
    DWORD cEntries;
    DWORD cUsed;
    DWORD cOrphans;
    DWORD cExpiredOrphans;
    DWORD cExpiredAbortedOrphans;
    DWORD cHandshaking;
} SecPkgCred_CacheInfo, *PSecPkgCred_CacheInfo;

struct _HMAPPER;

typedef struct _SCHANNEL_CRED {
    DWORD dwVersion;
    DWORD cCreds;
    PCCERT_CONTEXT *paCred;
    HCERTSTORE hRootStore;
    DWORD cMappers;
    struct _HMAPPER **aphMappers;
    DWORD cSupportedAlgs;
    ALG_ID *palgSupportedAlgs;
    DWORD grbitEnabledProtocols;
    DWORD dwMinimumCipherStrength;
    DWORD dwMaximumCipherStrength;
    DWORD dwSessionLifespan;
    DWORD dwFlags;
    DWORD reserved;
} SCHANNEL_CRED, *PSCHANNEL_CRED;

typedef struct _SCHANNEL_ALERT_TOKEN {
    DWORD dwTokenType;
    DWORD dwAlertType;
    DWORD dwAlertNumber;
} SCHANNEL_ALERT_TOKEN;

typedef struct _SSL_CREDENTIAL_CERTIFICATE {
    DWORD cbPrivateKey;
    PBYTE pPrivateKey;
    DWORD cbCertificate;
    PBYTE pCertificate;
    PSTR pszPassword;
} SSL_CREDENTIAL_CERTIFICATE, *PSSL_CREDENTIAL_CERTIFICATE;

struct _HMAPPER;

typedef struct _SCH_CRED {
    DWORD dwVersion;
    DWORD cCreds;
    PVOID *paSecret;
    PVOID *paPublic;
    DWORD cMappers;
    struct _HMAPPER **aphMappers;
} SCH_CRED, *PSCH_CRED;

typedef struct _SCH_CRED_SECRET_CAPI {
    DWORD dwType;
    HCRYPTPROV hProv;
} SCH_CRED_SECRET_CAPI, *PSCH_CRED_SECRET_CAPI;

typedef struct _SCH_CRED_SECRET_PRIVKEY {
    DWORD dwType;
    PBYTE pPrivateKey;
    DWORD cbPrivateKey;
    PSTR pszPassword;
} SCH_CRED_SECRET_PRIVKEY, *PSCH_CRED_SECRET_PRIVKEY;

typedef struct _SCH_CRED_PUBLIC_CERTCHAIN {
    DWORD dwType;
    DWORD cbCertChain;
    PBYTE pCertChain;
} SCH_CRED_PUBLIC_CERTCHAIN, *PSCH_CRED_PUBLIC_CERTCHAIN;

typedef struct _SCH_CRED_PUBLIC_CAPI {
    DWORD dwType;
    HCRYPTPROV hProv;
} SCH_CRED_PUBLIC_CAPI, *PSCH_CRED_PUBLIC_CAPI;

typedef struct _PctPublicKey {
    DWORD Type;
    DWORD cbKey;
    UCHAR pKey[1];
} PctPublicKey;

typedef struct _X509Certificate {
    DWORD Version;
    DWORD SerialNumber[4];
    ALG_ID SignatureAlgorithm;
    FILETIME ValidFrom;
    FILETIME ValidUntil;
    PSTR pszIssuer;
    PSTR pszSubject;
    PctPublicKey *pPublicKey;
} X509Certificate, *PX509Certificate;

typedef BOOL(WINAPI *SSL_CRACK_CERTIFICATE_FN)(PUCHAR,DWORD,BOOL,PX509Certificate*);
typedef VOID(WINAPI *SSL_FREE_CERTIFICATE_FN)(PX509Certificate);

#ifdef UNICODE
#define UNISP_NAME  UNISP_NAME_W
#define PCT1SP_NAME  PCT1SP_NAME_W
#define SSL2SP_NAME  SSL2SP_NAME_W
#define SSL3SP_NAME  SSL3SP_NAME_W
#define TLS1SP_NAME  TLS1SP_NAME_W
#define SSLOLD_NAME SSLOLD_NAME_W
#define PCTOLD_NAME PCTOLD_NAME_W
#else
#define UNISP_NAME  UNISP_NAME_A
#define PCT1SP_NAME  PCT1SP_NAME_A
#define SSL2SP_NAME  SSL2SP_NAME_A
#define SSL3SP_NAME  SSL3SP_NAME_A
#define TLS1SP_NAME  TLS1SP_NAME_A
#define SSLOLD_NAME SSLOLD_NAME_A
#define PCTOLD_NAME PCTOLD_NAME_A
#endif

BOOL SslEmptyCache(VOID);
BOOL SslGenerateKeyPair(PSSL_CREDENTIAL_CERTIFICATE,PSTR,PSTR,DWORD);
VOID SslGenerateRandomBits(PUCHAR,LONG);
BOOL SslCrackCertificate(PUCHAR,DWORD,DWORD,PX509Certificate*);
VOID SslFreeCertificate(PX509Certificate);
DWORD WINAPI SslGetMaximumKeySize(DWORD);
BOOL SslGetDefaultIssuers(PBYTE,DWORD*);

#endif /* _SCHANNEL_H */
