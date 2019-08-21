#ifndef _P2P_H
#define _P2P_H

/* Windows Peer To Peer infrastructure definitions */

#include <winsock2.h>
#include <pnrpns.h>
#include <ws2tcpip.h>

#if defined(WIN32_DEFAULT_LIBS)
#pragma comment(lib, "p2p.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2198)  /* Nameless field is not standard */
#endif

typedef enum peer_record_change_type_tag {
    PEER_RECORD_ADDED = 1,
    PEER_RECORD_UPDATED = 2,
    PEER_RECORD_DELETED = 3,
    PEER_RECORD_EXPIRED = 4,
} PEER_RECORD_CHANGE_TYPE;

typedef enum peer_connection_status_tag {
    PEER_CONNECTED = 1,
    PEER_DISCONNECTED = 2,
    PEER_CONNECTION_FAILED = 3,
} PEER_CONNECTION_STATUS;

typedef enum peer_connection_flags_tag {
    PEER_CONNECTION_NEIGHBOR = 0x0001,
    PEER_CONNECTION_DIRECT = 0x0002,
} PEER_CONNECTION_FLAGS;

typedef enum peer_record_flags_tag {
    PEER_RECORD_FLAG_AUTOREFRESH = 0x0001,
    PEER_RECORD_FLAG_DELETED = 0x0002,
} PEER_RECORD_FLAGS;

typedef void *HPEEREVENT;
typedef HPEEREVENT *PHPEEREVENT;

typedef void *HPEERENUM;
typedef HPEERENUM *PHPEERENUM;

typedef struct peer_version_data_tag {
    WORD wVersion;
    WORD wHighestVersion;
} PEER_VERSION_DATA, *PPEER_VERSION_DATA;

typedef struct peer_data_tag {
    ULONG cbData;
    PBYTE pbData;
} PEER_DATA, *PPEER_DATA;
typedef const PEER_DATA *PCPEER_DATA;

typedef struct peer_record_tag {
    DWORD dwSize;
    GUID type;
    GUID id;
    DWORD dwVersion;
    DWORD dwFlags;
    PWSTR pwzCreatorId;
    PWSTR pwzModifiedById;
    PWSTR pwzAttributes;
    FILETIME ftCreation;
    FILETIME ftExpiration;
    FILETIME ftLastModified;
    PEER_DATA securityData;
    PEER_DATA data;
} PEER_RECORD, *PPEER_RECORD;

typedef struct peer_address_tag {
    DWORD dwSize;
    SOCKADDR_IN6 sin6;
} PEER_ADDRESS, *PPEER_ADDRESS;
typedef const PEER_ADDRESS *PCPEER_ADDRESS;

typedef struct peer_connection_info_tag {
    DWORD dwSize;
    DWORD dwFlags;
    ULONGLONG ullConnectionId;
    ULONGLONG ullNodeId;
    PWSTR pwzPeerId;
    PEER_ADDRESS address;
} PEER_CONNECTION_INFO;

typedef struct peer_event_incoming_data_tag {
    DWORD dwSize;
    ULONGLONG ullConnectionId;
    GUID type;
    PEER_DATA data;
} PEER_EVENT_INCOMING_DATA, *PPEER_EVENT_INCOMING_DATA;

typedef struct peer_event_record_change_data_tag {
    DWORD dwSize;
    PEER_RECORD_CHANGE_TYPE changeType;
    GUID recordId;
    GUID recordType;
} PEER_EVENT_RECORD_CHANGE_DATA, *PPEER_EVENT_RECORD_CHANGE_DATA;

typedef struct peer_event_connection_change_data_tag {
    DWORD dwSize;
    PEER_CONNECTION_STATUS status;
    ULONGLONG ullConnectionId;
    ULONGLONG ullNodeId;
#if NTDDI_VERSION >= NTDDI_VISTA
    ULONGLONG ullNextConnectionId;
    HRESULT hrConnectionFailedReason;
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
} PEER_EVENT_CONNECTION_CHANGE_DATA, *PPEER_EVENT_CONNECTION_CHANGE_DATA;

typedef struct peer_event_synchronized_data_tag {
    DWORD dwSize;
    GUID recordType;
} PEER_EVENT_SYNCHRONIZED_DATA, *PPEER_EVENT_SYNCHRONIZED_DATA;

#ifndef NO_P2P_GRAPH

typedef PVOID HGRAPH, *PHGRAPH;

#define PEER_GRAPH_VERSION  MAKEWORD(1,0)

typedef enum peer_graph_event_type_tag {
    PEER_GRAPH_EVENT_STATUS_CHANGED = 1,
    PEER_GRAPH_EVENT_PROPERTY_CHANGED = 2,
    PEER_GRAPH_EVENT_RECORD_CHANGED = 3,
    PEER_GRAPH_EVENT_DIRECT_CONNECTION = 4,
    PEER_GRAPH_EVENT_NEIGHBOR_CONNECTION = 5,
    PEER_GRAPH_EVENT_INCOMING_DATA = 6,
    PEER_GRAPH_EVENT_CONNECTION_REQUIRED = 7,
    PEER_GRAPH_EVENT_NODE_CHANGED = 8,
    PEER_GRAPH_EVENT_SYNCHRONIZED = 9,
} PEER_GRAPH_EVENT_TYPE;

typedef enum peer_node_change_type_tag {
    PEER_NODE_CHANGE_CONNECTED = 1,
    PEER_NODE_CHANGE_DISCONNECTED = 2,
    PEER_NODE_CHANGE_UPDATED = 3,
} PEER_NODE_CHANGE_TYPE;

typedef enum peer_graph_status_flags_tag {
    PEER_GRAPH_STATUS_LISTENING = 0x0001,
    PEER_GRAPH_STATUS_HAS_CONNECTIONS = 0x0002,
    PEER_GRAPH_STATUS_SYNCHRONIZED = 0x0004,
} PEER_GRAPH_STATUS_FLAGS;

typedef enum peer_graph_property_flags_tag {
    PEER_GRAPH_PROPERTY_HEARTBEATS = 0x0001,
    PEER_GRAPH_PROPERTY_DEFER_EXPIRATION = 0x0002,
} PEER_GRAPH_PROPERTY_FLAGS;

typedef enum peer_graph_scope_tag {
    PEER_GRAPH_SCOPE_ANY = 0,
    PEER_GRAPH_SCOPE_GLOBAL = 1,
    PEER_GRAPH_SCOPE_SITELOCAL = 2,
    PEER_GRAPH_SCOPE_LINKLOCAL = 3,
    PEER_GRAPH_SCOPE_LOOPBACK = 4
} PEER_GRAPH_SCOPE;

typedef struct peer_graph_properties_tag {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwScope;
    DWORD dwMaxRecordSize;
    PWSTR pwzGraphId;
    PWSTR pwzCreatorId;
    PWSTR pwzFriendlyName;
    PWSTR pwzComment;
    ULONG ulPresenceLifetime;
    ULONG cPresenceMax;
} PEER_GRAPH_PROPERTIES, *PPEER_GRAPH_PROPERTIES;

typedef struct peer_node_info_tag {
    DWORD dwSize;
    ULONGLONG ullNodeId;
    PWSTR pwzPeerId;
    ULONG cAddresses;
    PPEER_ADDRESS pAddresses;
    PWSTR pwzAttributes;
} PEER_NODE_INFO, *PPEER_NODE_INFO;

typedef struct peer_event_node_change_data_tag {
    DWORD dwSize;
    PEER_NODE_CHANGE_TYPE changeType;
    ULONGLONG ullNodeId;
    PWSTR pwzPeerId;
} PEER_EVENT_NODE_CHANGE_DATA, *PPEER_EVENT_NODE_CHANGE_DATA;

typedef struct peer_graph_event_registration_tag {
    PEER_GRAPH_EVENT_TYPE eventType;
    GUID *pType;
} PEER_GRAPH_EVENT_REGISTRATION, *PPEER_GRAPH_EVENT_REGISTRATION;

typedef struct peer_graph_event_data_tag {
    PEER_GRAPH_EVENT_TYPE eventType;
    union {
        PEER_GRAPH_STATUS_FLAGS dwStatus;
        PEER_EVENT_INCOMING_DATA incomingData;
        PEER_EVENT_RECORD_CHANGE_DATA recordChangeData;
        PEER_EVENT_CONNECTION_CHANGE_DATA connectionChangeData;
        PEER_EVENT_NODE_CHANGE_DATA nodeChangeData;
        PEER_EVENT_SYNCHRONIZED_DATA synchronizedData;
    };
} PEER_GRAPH_EVENT_DATA, *PPEER_GRAPH_EVENT_DATA;


typedef HRESULT(CALLBACK *PFNPEER_VALIDATE_RECORD)(HGRAPH,PVOID,PPEER_RECORD,PEER_RECORD_CHANGE_TYPE);
typedef HRESULT(CALLBACK *PFNPEER_SECURE_RECORD)(HGRAPH,PVOID,PPEER_RECORD,PEER_RECORD_CHANGE_TYPE,PPEER_DATA*);
typedef HRESULT(CALLBACK *PFNPEER_FREE_SECURITY_DATA)(HGRAPH,PVOID,PPEER_DATA);

typedef struct peer_security_interface_tag {
    DWORD dwSize;
    PWSTR pwzSspFilename;
    PWSTR pwzPackageName;
    ULONG cbSecurityInfo;
    PBYTE pbSecurityInfo;
    PVOID pvContext;
    PFNPEER_VALIDATE_RECORD pfnValidateRecord;
    PFNPEER_SECURE_RECORD pfnSecureRecord;
    PFNPEER_FREE_SECURITY_DATA pfnFreeSecurityData;
} PEER_SECURITY_INTERFACE  , *PPEER_SECURITY_INTERFACE;

HRESULT WINAPI PeerGraphStartup(WORD, PPEER_VERSION_DATA);
HRESULT WINAPI PeerGraphShutdown(void);
VOID WINAPI PeerGraphFreeData(PVOID);
HRESULT WINAPI PeerGraphGetItemCount(HPEERENUM, ULONG *);
HRESULT WINAPI PeerGraphGetNextItem(HPEERENUM, ULONG *, PVOID **);
HRESULT WINAPI PeerGraphEndEnumeration(HPEERENUM);
HRESULT WINAPI PeerGraphCreate(PPEER_GRAPH_PROPERTIES, PCWSTR, PPEER_SECURITY_INTERFACE, HGRAPH *);
HRESULT WINAPI PeerGraphOpen(PCWSTR, PCWSTR, PCWSTR, PPEER_SECURITY_INTERFACE, ULONG, GUID *, HGRAPH *);
HRESULT WINAPI PeerGraphListen(HGRAPH, DWORD, DWORD, WORD);
HRESULT WINAPI PeerGraphConnect(HGRAPH, PCWSTR, PPEER_ADDRESS, ULONGLONG *);
HRESULT WINAPI PeerGraphClose(HGRAPH);
HRESULT WINAPI PeerGraphDelete(PCWSTR, PCWSTR, PCWSTR);
HRESULT WINAPI PeerGraphGetStatus(HGRAPH, DWORD *);
HRESULT WINAPI PeerGraphGetProperties(HGRAPH, PPEER_GRAPH_PROPERTIES *);
HRESULT WINAPI PeerGraphSetProperties(HGRAPH, PPEER_GRAPH_PROPERTIES);

HRESULT WINAPI PeerGraphRegisterEvent(HGRAPH, HANDLE, ULONG, PEER_GRAPH_EVENT_REGISTRATION *, HPEEREVENT *);
HRESULT WINAPI PeerGraphUnregisterEvent(HPEEREVENT);
HRESULT WINAPI PeerGraphGetEventData(HPEEREVENT, PPEER_GRAPH_EVENT_DATA *);

HRESULT WINAPI PeerGraphGetRecord(HGRAPH, GUID *, PPEER_RECORD *);
HRESULT WINAPI PeerGraphAddRecord(HGRAPH, PPEER_RECORD, GUID *);
HRESULT WINAPI PeerGraphUpdateRecord(HGRAPH, PPEER_RECORD);
HRESULT WINAPI PeerGraphDeleteRecord(HGRAPH, GUID *, BOOL);
HRESULT WINAPI PeerGraphEnumRecords(HGRAPH, GUID *, PCWSTR, HPEERENUM *);
HRESULT WINAPI PeerGraphSearchRecords(HGRAPH, PCWSTR, HPEERENUM *);
HRESULT WINAPI PeerGraphExportDatabase(HGRAPH, PCWSTR);
HRESULT WINAPI PeerGraphImportDatabase(HGRAPH, PCWSTR);
HRESULT WINAPI PeerGraphValidateDeferredRecords(HGRAPH, ULONG, GUID *);

HRESULT WINAPI PeerGraphOpenDirectConnection(HGRAPH, PCWSTR, PPEER_ADDRESS, ULONGLONG *);
HRESULT WINAPI PeerGraphSendData(HGRAPH, ULONGLONG, GUID *, ULONG, PVOID);
HRESULT WINAPI PeerGraphCloseDirectConnection(HGRAPH, ULONGLONG);
HRESULT WINAPI PeerGraphEnumConnections(HGRAPH, DWORD, HPEERENUM *);
HRESULT WINAPI PeerGraphEnumNodes(HGRAPH, PCWSTR, HPEERENUM *);
HRESULT WINAPI PeerGraphSetPresence(HGRAPH, BOOL);
HRESULT WINAPI PeerGraphGetNodeInfo(HGRAPH, ULONGLONG, PPEER_NODE_INFO *);
HRESULT WINAPI PeerGraphSetNodeAttributes(HGRAPH, PCWSTR);
HRESULT WINAPI PeerGraphPeerTimeToUniversalTime(HGRAPH, FILETIME *, FILETIME *);
HRESULT WINAPI PeerGraphUniversalTimeToPeerTime(HGRAPH, FILETIME *, FILETIME *);

#endif /* NO_P2P_GRAPH */

#if (!(defined(NO_P2P_GROUP)) || (!defined(NO_P2P_IDENTITY)))

#include <wincrypt.h>

VOID WINAPI PeerFreeData(LPCVOID);
HRESULT WINAPI PeerGetItemCount(HPEERENUM, ULONG *);
HRESULT WINAPI PeerGetNextItem(HPEERENUM, ULONG *, PVOID **);
HRESULT WINAPI PeerEndEnumeration(HPEERENUM);

#endif

#ifndef NO_P2P_GROUP

typedef PVOID HGROUP, *PHGROUP;
typedef GUID PEER_ROLE_ID;

#if NTDDI_VERSION >= NTDDI_VISTA
#define PEER_GROUP_VERSION  MAKEWORD(1,1)
#else
#define PEER_GROUP_VERSION  MAKEWORD(1,0)
#endif

typedef enum peer_group_event_type_tag {
    PEER_GROUP_EVENT_STATUS_CHANGED = 1,
    PEER_GROUP_EVENT_PROPERTY_CHANGED = 2,
    PEER_GROUP_EVENT_RECORD_CHANGED = 3,
    PEER_GROUP_EVENT_DIRECT_CONNECTION = 4,
    PEER_GROUP_EVENT_NEIGHBOR_CONNECTION = 5,
    PEER_GROUP_EVENT_INCOMING_DATA = 6,
    PEER_GROUP_EVENT_MEMBER_CHANGED = 8,
    PEER_GROUP_EVENT_CONNECTION_FAILED = 10
} PEER_GROUP_EVENT_TYPE;

typedef enum peer_group_status_tag {
    PEER_GROUP_STATUS_LISTENING = 0x0001,
    PEER_GROUP_STATUS_HAS_CONNECTIONS = 0x0002,
} PEER_GROUP_STATUS;

typedef enum peer_group_property_flags_tag {
    PEER_MEMBER_DATA_OPTIONAL = 0x0001,
    PEER_DISABLE_PRESENCE = 0x0002,
    PEER_DEFER_EXPIRATION = 0x0004,
} PEER_GROUP_PROPERTY_FLAGS;

#if NTDDI_VERSION >= NTDDI_VISTA
typedef enum peer_group_authentication_scheme_tag {
    PEER_GROUP_GMC_AUTHENTICATION = 0x00000001,
    PEER_GROUP_PASSWORD_AUTHENTICATION = 0x00000002,
} PEER_GROUP_AUTHENTICATION_SCHEME;
#endif /* NTDDI_VERSION >= NTDDI_VISTA */

typedef enum peer_member_flags_tag {
    PEER_MEMBER_PRESENT = 0x0001,
} PEER_MEMBER_FLAGS;

typedef enum peer_member_change_type_tag {
    PEER_MEMBER_CONNECTED = 1,
    PEER_MEMBER_DISCONNECTED = 2,
    PEER_MEMBER_UPDATED = 3,
    PEER_MEMBER_JOINED = 4,
    PEER_MEMBER_LEFT = 5,
} PEER_MEMBER_CHANGE_TYPE;

typedef enum peer_issue_credential_flags_tag {
    PEER_GROUP_STORE_CREDENTIALS = 0x0001,
} PEER_GROUP_ISSUE_CREDENTIAL_FLAGS;

typedef struct peer_credential_info_tag {
    DWORD dwSize;
    DWORD dwFlags;
    PWSTR pwzFriendlyName;
    CERT_PUBLIC_KEY_INFO *pPublicKey;
    PWSTR pwzIssuerPeerName;
    PWSTR pwzIssuerFriendlyName;
    FILETIME ftValidityStart;
    FILETIME ftValidityEnd;
    ULONG cRoles;
    PEER_ROLE_ID *pRoles;
} PEER_CREDENTIAL_INFO, *PPEER_CREDENTIAL_INFO;

typedef struct peer_member_tag {
    DWORD dwSize;
    DWORD dwFlags;
    PWSTR pwzIdentity;
    PWSTR pwzAttributes;
    ULONGLONG ullNodeId;
    ULONG cAddresses;
    PEER_ADDRESS *pAddresses;
    PEER_CREDENTIAL_INFO *pCredentialInfo;
} PEER_MEMBER, *PPEER_MEMBER;

typedef struct peer_group_properties_tag {
    DWORD dwSize;
    DWORD dwFlags;
    PWSTR pwzCloud;
    PWSTR pwzClassifier;
    PWSTR pwzGroupPeerName;
    PWSTR pwzCreatorPeerName;
    PWSTR pwzFriendlyName;
    PWSTR pwzComment;
    ULONG ulMemberDataLifetime;
    ULONG ulPresenceLifetime;
#if NTDDI_VERSION >= NTDDI_VISTA
    DWORD dwAuthenticationSchemes;
    PWSTR pwzGroupPassword;
    PEER_ROLE_ID groupPasswordRole;
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
} PEER_GROUP_PROPERTIES, *PPEER_GROUP_PROPERTIES;

typedef struct peer_invitation_info_tag {
    DWORD dwSize;
    DWORD dwFlags;
    PWSTR pwzCloudName;
    DWORD dwScope;
    DWORD dwCloudFlags;
    PWSTR pwzGroupPeerName;
    PWSTR pwzIssuerPeerName;
    PWSTR pwzSubjectPeerName;
    PWSTR pwzGroupFriendlyName;
    PWSTR pwzIssuerFriendlyName;
    PWSTR pwzSubjectFriendlyName;
    FILETIME ftValidityStart;
    FILETIME ftValidityEnd;
    ULONG cRoles;
    PEER_ROLE_ID *pRoles;
    ULONG cClassifiers;
    PWSTR *ppwzClassifiers;
    CERT_PUBLIC_KEY_INFO *pSubjectPublicKey;
#if NTDDI_VERSION >= NTDDI_VISTA
    PEER_GROUP_AUTHENTICATION_SCHEME authScheme;
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
} PEER_INVITATION_INFO, *PPEER_INVITATION_INFO;

typedef struct peer_event_member_change_data_tag {
    DWORD dwSize;
    PEER_MEMBER_CHANGE_TYPE changeType;
    PWSTR pwzIdentity;
} PEER_EVENT_MEMBER_CHANGE_DATA  , *PPEER_EVENT_MEMBER_CHANGE_DATA;

typedef struct peer_group_event_registration_tag {
    PEER_GROUP_EVENT_TYPE eventType;
    GUID *pType;
} PEER_GROUP_EVENT_REGISTRATION  , *PPEER_GROUP_EVENT_REGISTRATION;

typedef struct peer_group_event_data_tag {
    PEER_GROUP_EVENT_TYPE eventType;
    union {
        PEER_GROUP_STATUS dwStatus;
        PEER_EVENT_INCOMING_DATA incomingData;
        PEER_EVENT_RECORD_CHANGE_DATA recordChangeData;
        PEER_EVENT_CONNECTION_CHANGE_DATA connectionChangeData;
        PEER_EVENT_MEMBER_CHANGE_DATA memberChangeData;
        HRESULT hrConnectionFailedReason;
    };
} PEER_GROUP_EVENT_DATA, *PPEER_GROUP_EVENT_DATA;

typedef struct peer_name_pair_tag {
    DWORD dwSize;
    PWSTR pwzPeerName;
    PWSTR pwzFriendlyName;
} PEER_NAME_PAIR, *PPEER_NAME_PAIR;

HRESULT WINAPI PeerGroupStartup(WORD, PPEER_VERSION_DATA);
HRESULT WINAPI PeerGroupShutdown(void);
HRESULT WINAPI PeerGroupCreate(PPEER_GROUP_PROPERTIES, HGROUP *);
HRESULT WINAPI PeerGroupOpen(PCWSTR, PCWSTR, PCWSTR, HGROUP *);
HRESULT WINAPI PeerGroupJoin(PCWSTR, PCWSTR, PCWSTR, HGROUP *);
#if NTDDI_VERSION >= NTDDI_VISTA
HRESULT WINAPI PeerGroupPasswordJoin(PCWSTR, PCWSTR, PCWSTR, PCWSTR, HGROUP *);
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
HRESULT WINAPI PeerGroupConnect(HGROUP);
#if NTDDI_VERSION >= NTDDI_VISTA
HRESULT WINAPI PeerGroupConnectByAddress(HGROUP, ULONG, PPEER_ADDRESS);
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
HRESULT WINAPI PeerGroupClose(HGROUP);
HRESULT WINAPI PeerGroupDelete(PCWSTR, PCWSTR);
HRESULT WINAPI PeerGroupCreateInvitation(HGROUP, PCWSTR, FILETIME *, ULONG, GUID *, PWSTR *);
#if NTDDI_VERSION >= NTDDI_VISTA
HRESULT WINAPI PeerGroupCreatePasswordInvitation(HGROUP, PWSTR *);
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
HRESULT WINAPI PeerGroupParseInvitation(PCWSTR, PPEER_INVITATION_INFO *);
HRESULT WINAPI PeerGroupGetStatus(HGROUP, DWORD *);
HRESULT WINAPI PeerGroupGetProperties(HGROUP, PPEER_GROUP_PROPERTIES *);
HRESULT WINAPI PeerGroupSetProperties(HGROUP, PPEER_GROUP_PROPERTIES);
HRESULT WINAPI PeerGroupEnumMembers(HGROUP, DWORD, PCWSTR, HPEERENUM *);
HRESULT WINAPI PeerGroupOpenDirectConnection(HGROUP, PCWSTR, PPEER_ADDRESS, ULONGLONG *);
HRESULT WINAPI PeerGroupCloseDirectConnection(HGROUP, ULONGLONG);
HRESULT WINAPI PeerGroupEnumConnections(HGROUP, DWORD, HPEERENUM *);
HRESULT WINAPI PeerGroupSendData(HGROUP, ULONGLONG, GUID *, ULONG, PVOID);

HRESULT WINAPI PeerGroupRegisterEvent(HGROUP, HANDLE, DWORD, PEER_GROUP_EVENT_REGISTRATION *, HPEEREVENT *);
HRESULT WINAPI PeerGroupUnregisterEvent(HPEEREVENT);
HRESULT WINAPI PeerGroupGetEventData(HPEEREVENT, PPEER_GROUP_EVENT_DATA *);

HRESULT WINAPI PeerGroupGetRecord(HGROUP, GUID *, PPEER_RECORD *);
HRESULT WINAPI PeerGroupAddRecord(HGROUP, PPEER_RECORD, GUID *);
HRESULT WINAPI PeerGroupUpdateRecord(HGROUP, PPEER_RECORD);
HRESULT WINAPI PeerGroupDeleteRecord(HGROUP, GUID *);
HRESULT WINAPI PeerGroupEnumRecords(HGROUP, GUID *, HPEERENUM *);
HRESULT WINAPI PeerGroupSearchRecords(HGROUP, PCWSTR, HPEERENUM *);
HRESULT WINAPI PeerGroupExportDatabase(HGROUP, PCWSTR);
HRESULT WINAPI PeerGroupImportDatabase(HGROUP, PCWSTR);
HRESULT WINAPI PeerGroupIssueCredentials(HGROUP, PCWSTR, PEER_CREDENTIAL_INFO *, DWORD, PWSTR *);
HRESULT WINAPI PeerGroupExportConfig(HGROUP, PCWSTR, PWSTR *);
HRESULT WINAPI PeerGroupImportConfig(PCWSTR, PCWSTR, BOOL, PWSTR *, PWSTR *);
HRESULT WINAPI PeerGroupPeerTimeToUniversalTime(HGROUP, FILETIME *, FILETIME *);
HRESULT WINAPI PeerGroupUniversalTimeToPeerTime(HGROUP, FILETIME *, FILETIME *);

#if NTDDI_VERSION >= NTDDI_WIN7
HRESULT WINAPI PeerGroupResumePasswordAuthentication(HGROUP,HPEEREVENT);
#endif /* NTDDI_VERSION >= NTDDI_WIN7 */

#endif /* NO_P2P_GROUP */

#ifndef NO_P2P_IDENTITY

HRESULT WINAPI PeerIdentityCreate(PCWSTR, PCWSTR, HCRYPTPROV, PWSTR *);
HRESULT WINAPI PeerIdentityGetFriendlyName(PCWSTR, PWSTR *);
HRESULT WINAPI PeerIdentitySetFriendlyName(PCWSTR, PCWSTR);
HRESULT WINAPI PeerIdentityGetCryptKey(PCWSTR, HCRYPTPROV *);
HRESULT WINAPI PeerIdentityDelete(PCWSTR);
HRESULT WINAPI PeerEnumIdentities(HPEERENUM *);
HRESULT WINAPI PeerEnumGroups(PCWSTR, HPEERENUM *);
HRESULT WINAPI PeerCreatePeerName(PCWSTR, PCWSTR, PWSTR *);
HRESULT WINAPI PeerIdentityGetXML(PCWSTR, PWSTR *);
HRESULT WINAPI PeerIdentityExport(PCWSTR, PCWSTR, PWSTR *);
HRESULT WINAPI PeerIdentityImport(PCWSTR, PCWSTR, PWSTR *);
HRESULT WINAPI PeerIdentityGetDefault(PWSTR *);

#endif /* NO_P2P_IDENTITY */

#ifndef NO_P2P_COLLABORATION

#define PEER_COLLAB_VERSION  MAKEWORD(1,0)

typedef enum peer_signin_flags_tag {
    PEER_SIGNIN_NONE = 0x0,
    PEER_SIGNIN_NEAR_ME = 0x1,
    PEER_SIGNIN_INTERNET = 0x2,
    PEER_SIGNIN_ALL = PEER_SIGNIN_INTERNET | PEER_SIGNIN_NEAR_ME
} PEER_SIGNIN_FLAGS;

typedef enum peer_watch_permission_tag {
    PEER_WATCH_BLOCKED = 0,
    PEER_WATCH_ALLOWED = 1
} PEER_WATCH_PERMISSION;

typedef enum peer_publication_scope_tag {
    PEER_PUBLICATION_SCOPE_NONE = 0x0,
    PEER_PUBLICATION_SCOPE_NEAR_ME = 0x1,
    PEER_PUBLICATION_SCOPE_INTERNET = 0x2,
    PEER_PUBLICATION_SCOPE_ALL = PEER_PUBLICATION_SCOPE_NEAR_ME | PEER_PUBLICATION_SCOPE_INTERNET
} PEER_PUBLICATION_SCOPE;

typedef struct peer_application_tag {
    GUID id;
    PEER_DATA data;
    PWSTR pwzDescription;
} PEER_APPLICATION  , *PPEER_APPLICATION;
typedef const PEER_APPLICATION *PCPEER_APPLICATION;

typedef struct peer_object_tag {
    GUID id;
    PEER_DATA data;
    DWORD dwPublicationScope;
} PEER_OBJECT, *PPEER_OBJECT;
typedef const PEER_OBJECT *PCPEER_OBJECT;

typedef struct peer_contact_tag {
    PWSTR pwzPeerName;
    PWSTR pwzNickName;
    PWSTR pwzDisplayName;
    PWSTR pwzEmailAddress;
    BOOL fWatch;
    PEER_WATCH_PERMISSION WatcherPermissions;
    PEER_DATA credentials;
} PEER_CONTACT, *PPEER_CONTACT;
typedef const PEER_CONTACT *PCPEER_CONTACT;

typedef struct peer_endpoint_tag {
    PEER_ADDRESS address;
    PWSTR pwzEndpointName;
} PEER_ENDPOINT, *PPEER_ENDPOINT;
typedef const PEER_ENDPOINT *PCPEER_ENDPOINT;

typedef struct peer_people_near_me_tag {
    PWSTR pwzNickName;
    PEER_ENDPOINT endpoint;
    GUID id;
} PEER_PEOPLE_NEAR_ME, *PPEER_PEOPLE_NEAR_ME;
typedef const PEER_PEOPLE_NEAR_ME *PCPEER_PEOPLE_NEAR_ME;
typedef PPEER_PEOPLE_NEAR_ME *PPPEER_PEOPLE_NEAR_ME;

HRESULT WINAPI PeerCollabStartup(WORD);
HRESULT WINAPI PeerCollabShutdown(void);
HRESULT WINAPI PeerCollabSignin(HWND, DWORD);
HRESULT WINAPI PeerCollabSignout(DWORD);
HRESULT WINAPI PeerCollabGetSigninOptions(DWORD *);

typedef enum peer_invitation_response_type_tag {
    PEER_INVITATION_RESPONSE_DECLINED = 0,
    PEER_INVITATION_RESPONSE_ACCEPTED = 1,
    PEER_INVITATION_RESPONSE_EXPIRED = 2,
    PEER_INVITATION_RESPONSE_ERROR = 3
} PEER_INVITATION_RESPONSE_TYPE;

typedef enum peer_application_registration_type_tag {
    PEER_APPLICATION_CURRENT_USER = 0,
    PEER_APPLICATION_ALL_USERS = 1
} PEER_APPLICATION_REGISTRATION_TYPE;

typedef struct peer_invitation_tag {
    GUID applicationId;
    PEER_DATA applicationData;
    PWSTR pwzMessage;
} PEER_INVITATION, *PPEER_INVITATION;
typedef const PEER_INVITATION *PCPEER_INVITATION;

typedef struct peer_invitation_response_tag {
    PEER_INVITATION_RESPONSE_TYPE action;
    PWSTR pwzMessage;
    HRESULT hrExtendedInfo;
} PEER_INVITATION_RESPONSE, *PPEER_INVITATION_RESPONSE;
typedef const PEER_INVITATION_RESPONSE *PCPEER_INVITATION_RESPONSE;

typedef struct peer_app_launch_info_tag {
    PPEER_CONTACT pContact;
    PPEER_ENDPOINT pEndpoint;
    PPEER_INVITATION pInvitation;
} PEER_APP_LAUNCH_INFO, *PPEER_APP_LAUNCH_INFO;
typedef const PEER_APP_LAUNCH_INFO *PCPEER_APP_LAUNCH_INFO;

typedef struct peer_application_registration_info_tag {
    PEER_APPLICATION application;
    PWSTR pwzApplicationToLaunch;
    PWSTR pwzApplicationArguments;
    DWORD dwPublicationScope;
} PEER_APPLICATION_REGISTRATION_INFO, *PPEER_APPLICATION_REGISTRATION_INFO;
typedef const PEER_APPLICATION_REGISTRATION_INFO *PCPEER_APPLICATION_REGISTRATION_INFO;

HRESULT WINAPI PeerCollabAsyncInviteContact(PCPEER_CONTACT, PCPEER_ENDPOINT, PCPEER_INVITATION, HANDLE, HANDLE *);
HRESULT WINAPI PeerCollabGetInvitationResponse(HANDLE, PPEER_INVITATION_RESPONSE *);
HRESULT WINAPI PeerCollabCancelInvitation(HANDLE);
HRESULT WINAPI PeerCollabCloseHandle(HANDLE);
HRESULT WINAPI PeerCollabInviteContact(PCPEER_CONTACT, PCPEER_ENDPOINT, PCPEER_INVITATION, PPEER_INVITATION_RESPONSE *);
HRESULT WINAPI PeerCollabAsyncInviteEndpoint(PCPEER_ENDPOINT, PCPEER_INVITATION, HANDLE, HANDLE *);
HRESULT WINAPI PeerCollabInviteEndpoint(PCPEER_ENDPOINT, PCPEER_INVITATION, PPEER_INVITATION_RESPONSE *);

HRESULT WINAPI PeerCollabGetAppLaunchInfo(PPEER_APP_LAUNCH_INFO *);

HRESULT WINAPI PeerCollabRegisterApplication(PCPEER_APPLICATION_REGISTRATION_INFO, PEER_APPLICATION_REGISTRATION_TYPE);
HRESULT WINAPI PeerCollabUnregisterApplication(GUID *, PEER_APPLICATION_REGISTRATION_TYPE);
HRESULT WINAPI PeerCollabGetApplicationRegistrationInfo(GUID *, PEER_APPLICATION_REGISTRATION_TYPE, PPEER_APPLICATION_REGISTRATION_INFO *);
HRESULT WINAPI PeerCollabEnumApplicationRegistrationInfo(PEER_APPLICATION_REGISTRATION_TYPE, HPEERENUM *);

typedef enum peer_presence_status_tag {
    PEER_PRESENCE_OFFLINE = 0,
    PEER_PRESENCE_OUT_TO_LUNCH = 1,
    PEER_PRESENCE_AWAY = 2,
    PEER_PRESENCE_BE_RIGHT_BACK = 3,
    PEER_PRESENCE_IDLE = 4,
    PEER_PRESENCE_BUSY = 5,
    PEER_PRESENCE_ON_THE_PHONE = 6,
    PEER_PRESENCE_ONLINE = 7
} PEER_PRESENCE_STATUS;

typedef struct peer_presence_info_tag {
    PEER_PRESENCE_STATUS status;
    PWSTR pwzDescriptiveText;
} PEER_PRESENCE_INFO  , *PPEER_PRESENCE_INFO;
typedef const PEER_PRESENCE_INFO *PCPEER_PRESENCE_INFO;

HRESULT WINAPI PeerCollabGetPresenceInfo(PCPEER_ENDPOINT, PPEER_PRESENCE_INFO *);
HRESULT WINAPI PeerCollabEnumApplications(PCPEER_ENDPOINT, GUID *, HPEERENUM *);
HRESULT WINAPI PeerCollabEnumObjects(PCPEER_ENDPOINT, GUID *, HPEERENUM *);
HRESULT WINAPI PeerCollabEnumEndpoints(PCPEER_CONTACT, HPEERENUM *);
HRESULT WINAPI PeerCollabRefreshEndpointData(PCPEER_ENDPOINT);
HRESULT WINAPI PeerCollabDeleteEndpointData(PCPEER_ENDPOINT);
HRESULT WINAPI PeerCollabQueryContactData(PCPEER_ENDPOINT, PWSTR *);
HRESULT WINAPI PeerCollabSubscribeEndpointData(const PCPEER_ENDPOINT);
HRESULT WINAPI PeerCollabUnsubscribeEndpointData(const PCPEER_ENDPOINT);

HRESULT WINAPI PeerCollabSetPresenceInfo(PCPEER_PRESENCE_INFO);
HRESULT WINAPI PeerCollabGetEndpointName(PWSTR *);
HRESULT WINAPI PeerCollabSetEndpointName(PCWSTR);
HRESULT WINAPI PeerCollabSetObject(PCPEER_OBJECT);
HRESULT WINAPI PeerCollabDeleteObject(GUID *);

typedef enum peer_change_type_tag {
    PEER_CHANGE_ADDED = 0,
    PEER_CHANGE_DELETED = 1,
    PEER_CHANGE_UPDATED = 2
} PEER_CHANGE_TYPE;

typedef enum peer_collab_event_type_tag {
    PEER_EVENT_WATCHLIST_CHANGED = 1,
    PEER_EVENT_ENDPOINT_CHANGED = 2,
    PEER_EVENT_ENDPOINT_PRESENCE_CHANGED = 3,
    PEER_EVENT_ENDPOINT_APPLICATION_CHANGED = 4,
    PEER_EVENT_ENDPOINT_OBJECT_CHANGED = 5,
    PEER_EVENT_MY_ENDPOINT_CHANGED = 6,
    PEER_EVENT_MY_PRESENCE_CHANGED = 7,
    PEER_EVENT_MY_APPLICATION_CHANGED = 8,
    PEER_EVENT_MY_OBJECT_CHANGED = 9,
    PEER_EVENT_PEOPLE_NEAR_ME_CHANGED = 10,
    PEER_EVENT_REQUEST_STATUS_CHANGED = 11
} PEER_COLLAB_EVENT_TYPE;

typedef struct peer_collab_event_registration_tag {
    PEER_COLLAB_EVENT_TYPE eventType;
    GUID *pInstance;
} PEER_COLLAB_EVENT_REGISTRATION, *PPEER_COLLAB_EVENT_REGISTRATION;

typedef struct peer_event_watchlist_changed_data_tag {
    PPEER_CONTACT pContact;
    PEER_CHANGE_TYPE changeType;
} PEER_EVENT_WATCHLIST_CHANGED_DATA, *PPEER_EVENT_WATCHLIST_CHANGED_DATA;

typedef struct peer_event_presence_changed_data_tag {
    PPEER_CONTACT pContact;
    PPEER_ENDPOINT pEndpoint;
    PEER_CHANGE_TYPE changeType;
    PPEER_PRESENCE_INFO pPresenceInfo;
} PEER_EVENT_PRESENCE_CHANGED_DATA, *PPEER_EVENT_PRESENCE_CHANGED_DATA;

typedef struct peer_event_application_changed_data_tag {
    PPEER_CONTACT pContact;
    PPEER_ENDPOINT pEndpoint;
    PEER_CHANGE_TYPE changeType;
    PPEER_APPLICATION pApplication;
} PEER_EVENT_APPLICATION_CHANGED_DATA, *PPEER_EVENT_APPLICATION_CHANGED_DATA;

typedef struct peer_event_object_changed_data_tag {
    PPEER_CONTACT pContact;
    PPEER_ENDPOINT pEndpoint;
    PEER_CHANGE_TYPE changeType;
    PPEER_OBJECT pObject;
} PEER_EVENT_OBJECT_CHANGED_DATA, *PPEER_EVENT_OBJECT_CHANGED_DATA;

typedef struct peer_event_endpoint_changed_data_tag {
    PPEER_CONTACT pContact;
    PPEER_ENDPOINT pEndpoint;
} PEER_EVENT_ENDPOINT_CHANGED_DATA, *PPEER_EVENT_ENDPOINT_CHANGED_DATA;

typedef struct peer_event_people_near_me_changed_data_tag {
    PEER_CHANGE_TYPE changeType;
    PPEER_PEOPLE_NEAR_ME pPeopleNearMe;
} PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA , *PPEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA;

typedef struct peer_event_request_status_changed_data_tag {
    PPEER_ENDPOINT pEndpoint;
    HRESULT hrChange;
} PEER_EVENT_REQUEST_STATUS_CHANGED_DATA, *PPEER_EVENT_REQUEST_STATUS_CHANGED_DATA;

typedef struct peer_collab_event_data_tag {
    PEER_COLLAB_EVENT_TYPE eventType;
    union {
        PEER_EVENT_WATCHLIST_CHANGED_DATA watchListChangedData;
        PEER_EVENT_PRESENCE_CHANGED_DATA presenceChangedData;
        PEER_EVENT_APPLICATION_CHANGED_DATA applicationChangedData;
        PEER_EVENT_OBJECT_CHANGED_DATA objectChangedData;
        PEER_EVENT_ENDPOINT_CHANGED_DATA endpointChangedData;
        PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA peopleNearMeChangedData;
        PEER_EVENT_REQUEST_STATUS_CHANGED_DATA requestStatusChangedData;
    };
} PEER_COLLAB_EVENT_DATA, *PPEER_COLLAB_EVENT_DATA;

HRESULT WINAPI PeerCollabRegisterEvent(HANDLE, DWORD, PEER_COLLAB_EVENT_REGISTRATION *, HPEEREVENT *);
HRESULT WINAPI PeerCollabGetEventData(HPEEREVENT, PPEER_COLLAB_EVENT_DATA *);
HRESULT WINAPI PeerCollabUnregisterEvent(HPEEREVENT);
HRESULT WINAPI PeerCollabEnumPeopleNearMe(HPEERENUM *);
HRESULT WINAPI PeerCollabAddContact(PCWSTR, PPEER_CONTACT *);
HRESULT WINAPI PeerCollabDeleteContact(PCWSTR);
HRESULT WINAPI PeerCollabGetContact(PCWSTR, PPEER_CONTACT *);
HRESULT WINAPI PeerCollabUpdateContact(PCPEER_CONTACT);
HRESULT WINAPI PeerCollabEnumContacts(HPEERENUM *);
HRESULT WINAPI PeerCollabExportContact(PCWSTR, PWSTR *);
HRESULT WINAPI PeerCollabParseContact(PCWSTR, PPEER_CONTACT *);

#endif /* NO_P2P_COLLABORATION */

#ifndef NO_P2P_PNRP

#define PNRP_VERSION  MAKEWORD(2,0)

#define PEER_PNRP_ALL_LINK_CLOUDS   L"PEER_PNRP_ALL_LINKS"
#define PEER_PNRP_AUTO_ADDRESSES  ((ULONG)(-1))

typedef PVOID HRESOLUTION, HREGISTRATION;

typedef struct peer_pnrp_endpoint_info_tag {
    PWSTR pwzPeerName;
    ULONG cAddresses;
    SOCKADDR **ppAddresses;
    PWSTR pwzComment;
    PEER_DATA payload;
} PEER_PNRP_ENDPOINT_INFO, *PPEER_PNRP_ENDPOINT_INFO;

typedef struct peer_pnrp_cloud_info_tag {
    PWSTR pwzCloudName;
    PNRP_SCOPE dwScope;
    DWORD dwScopeId;
} PEER_PNRP_CLOUD_INFO, *PPEER_PNRP_CLOUD_INFO;

typedef struct peer_pnrp_registration_info_tag {
    PWSTR pwzCloudName;
    PWSTR pwzPublishingIdentity;
    ULONG cAddresses;
    SOCKADDR **ppAddresses;
    WORD wPort;
    PWSTR pwzComment;
    PEER_DATA payload;
} PEER_PNRP_REGISTRATION_INFO, *PPEER_PNRP_REGISTRATION_INFO;

HRESULT WINAPI PeerNameToPeerHostName(PCWSTR, PWSTR *);
HRESULT WINAPI PeerHostNameToPeerName(PCWSTR, PWSTR *);
HRESULT WINAPI PeerPnrpStartup(WORD);
HRESULT WINAPI PeerPnrpShutdown(void);
HRESULT WINAPI PeerPnrpRegister(PCWSTR, PPEER_PNRP_REGISTRATION_INFO, HREGISTRATION *);
HRESULT WINAPI PeerPnrpUpdateRegistration(HREGISTRATION, PPEER_PNRP_REGISTRATION_INFO);
HRESULT WINAPI PeerPnrpUnregister(HREGISTRATION);
HRESULT WINAPI PeerPnrpResolve(PCWSTR, PCWSTR, ULONG *, PPEER_PNRP_ENDPOINT_INFO *);
HRESULT WINAPI PeerPnrpStartResolve(PCWSTR, PCWSTR, ULONG, HANDLE, HRESOLUTION *);
HRESULT WINAPI PeerPnrpGetCloudInfo(ULONG *, PPEER_PNRP_CLOUD_INFO *);
HRESULT WINAPI PeerPnrpGetEndpoint(HRESOLUTION, PPEER_PNRP_ENDPOINT_INFO *);
HRESULT WINAPI PeerPnrpEndResolve(HRESOLUTION);

#endif /* NO_P2P_PNRP */

#if __POCC__ >= 290
#pragma warn(pop)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* errors */

#ifndef FACILITY_P2P
#define FACILITY_P2P  99
#endif

#define PEER_E_IPV6_NOT_INSTALLED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0001)
#define PEER_E_NOT_INITIALIZED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0002)
#define PEER_E_CANNOT_START_SERVICE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0003)
#define PEER_E_NOT_LICENSED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0004)
#define PEER_E_INVALID_GRAPH  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0010)
#define PEER_E_DBNAME_CHANGED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0011)
#define PEER_E_DUPLICATE_GRAPH  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0012)
#define PEER_E_GRAPH_NOT_READY  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0013)
#define PEER_E_GRAPH_SHUTTING_DOWN  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0014)
#define PEER_E_GRAPH_IN_USE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0015)
#define PEER_E_INVALID_DATABASE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0016)
#define PEER_E_TOO_MANY_ATTRIBUTES  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0017)
#define PEER_E_CONNECTION_NOT_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0103)
#define PEER_E_CONNECT_SELF  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0106)
#define PEER_E_ALREADY_LISTENING  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0107)
#define PEER_E_NODE_NOT_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0108)
#define PEER_E_CONNECTION_FAILED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0109)
#define PEER_E_CONNECTION_NOT_AUTHENTICATED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x010A)
#define PEER_E_CONNECTION_REFUSED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x010B)
#define PEER_E_CLASSIFIER_TOO_LONG  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0201)
#define PEER_E_TOO_MANY_IDENTITIES  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0202)
#define PEER_E_NO_KEY_ACCESS  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0203)
#define PEER_E_GROUPS_EXIST  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0204)
#define PEER_E_RECORD_NOT_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0301)
#define PEER_E_DATABASE_ACCESSDENIED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0302)
#define PEER_E_DBINITIALIZATION_FAILED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0303)
#define PEER_E_MAX_RECORD_SIZE_EXCEEDED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0304)
#define PEER_E_DATABASE_ALREADY_PRESENT  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0305)
#define PEER_E_DATABASE_NOT_PRESENT  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0306)
#define PEER_E_IDENTITY_NOT_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0401)
#define PEER_E_EVENT_HANDLE_NOT_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0501)
#define PEER_E_INVALID_SEARCH  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0601)
#define PEER_E_INVALID_ATTRIBUTES  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0602)
#define PEER_E_INVITATION_NOT_TRUSTED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0701)
#define PEER_E_CHAIN_TOO_LONG  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0703)
#define PEER_E_INVALID_TIME_PERIOD  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0705)
#define PEER_E_CIRCULAR_CHAIN_DETECTED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0706)
#define PEER_E_CERT_STORE_CORRUPTED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x0801)
#define PEER_E_NO_CLOUD  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x1001)
#define PEER_E_CLOUD_NAME_AMBIGUOUS  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x1005)
#define PEER_E_INVALID_RECORD  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2010)
#define PEER_E_NOT_AUTHORIZED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2020)
#define PEER_E_PASSWORD_DOES_NOT_MEET_POLICY MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2021)
#define PEER_E_DEFERRED_VALIDATION  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2030)
#define PEER_E_INVALID_GROUP_PROPERTIES  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2040)
#define PEER_E_INVALID_PEER_NAME  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2050)
#define PEER_E_INVALID_CLASSIFIER  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2060)
#define PEER_E_INVALID_FRIENDLY_NAME  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2070)
#define PEER_E_INVALID_ROLE_PROPERTY  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2071)
#define PEER_E_INVALID_CLASSIFIER_PROPERTY  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2072)
#define PEER_E_INVALID_RECORD_EXPIRATION  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2080)
#define PEER_E_INVALID_CREDENTIAL_INFO  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2081)
#define PEER_E_INVALID_CREDENTIAL  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2082)
#define PEER_E_INVALID_RECORD_SIZE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2083)
#define PEER_E_UNSUPPORTED_VERSION  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2090)
#define PEER_E_GROUP_NOT_READY  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2091)
#define PEER_E_GROUP_IN_USE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2092)
#define PEER_E_INVALID_GROUP  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2093)
#define PEER_E_NO_MEMBERS_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2094)
#define PEER_E_NO_MEMBER_CONNECTIONS  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2095)
#define PEER_E_UNABLE_TO_LISTEN  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x2096)
#define PEER_E_IDENTITY_DELETED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x20A0)
#define PEER_E_SERVICE_NOT_AVAILABLE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x20A1)
#define PEER_E_CONTACT_NOT_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x6001)
#define PEER_S_GRAPH_DATA_CREATED  MAKE_HRESULT(SEVERITY_SUCCESS,FACILITY_P2P,0x0001)
#define PEER_S_NO_EVENT_DATA  MAKE_HRESULT(SEVERITY_SUCCESS,FACILITY_P2P,0x0002)
#define PEER_S_ALREADY_CONNECTED  MAKE_HRESULT(SEVERITY_SUCCESS,FACILITY_P2P,0x2000)
#define PEER_S_SUBSCRIPTION_EXISTS  MAKE_HRESULT(SEVERITY_SUCCESS,FACILITY_P2P,0x6000)
#define PEER_S_NO_CONNECTIVITY  MAKE_HRESULT(SEVERITY_SUCCESS,FACILITY_P2P,0x0005)
#define PEER_S_ALREADY_A_MEMBER  MAKE_HRESULT(SEVERITY_SUCCESS,FACILITY_P2P,0x0006)
#define PEER_E_CANNOT_CONVERT_PEER_NAME  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x4001)
#define PEER_E_INVALID_PEER_HOST_NAME  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x4002)
#define PEER_E_NO_MORE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x4003)
#define PEER_E_PNRP_DUPLICATE_PEER_NAME  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x4005)
#define PEER_E_INVITE_CANCELLED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x7000)
#define PEER_E_INVITE_RESPONSE_NOT_AVAILABLE  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x7001)
#define PEER_E_NOT_SIGNED_IN  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x7003)
#define PEER_E_PRIVACY_DECLINED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x7004)
#define PEER_E_TIMEOUT  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0x7005)
#define PEER_E_INVALID_ADDRESS  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0X7007)
#define PEER_E_FW_EXCEPTION_DISABLED  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0X7008)
#define PEER_E_FW_BLOCKED_BY_POLICY  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0X7009)
#define PEER_E_FW_BLOCKED_BY_SHIELDS_UP  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_P2P,0X700A)

#define WSA_PNRP_ERROR_BASE  11500
#define WSA_PNRP_CLOUD_NOT_FOUND  (WSA_PNRP_ERROR_BASE+1)
#define WSA_PNRP_CLOUD_DISABLED  (WSA_PNRP_ERROR_BASE+2)
#define WSA_PNRP_INVALID_IDENTITY  (WSA_PNRP_ERROR_BASE+3)
#define WSA_PNRP_TOO_MUCH_LOAD  (WSA_PNRP_ERROR_BASE+4)
#define WSA_PNRP_CLOUD_IS_SEARCH_ONLY  (WSA_PNRP_ERROR_BASE+5)
#define WSA_PNRP_CLIENT_INVALID_COMPARTMENT_ID (WSA_PNRP_ERROR_BASE+6)
#define WSA_PNRP_DUPLICATE_PEER_NAME  (WSA_PNRP_ERROR_BASE+8)

#define PEER_E_NOT_FOUND  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_NOT_FOUND)
#define PEER_E_DISK_FULL  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_DISK_FULL)
#define PEER_E_ALREADY_EXISTS  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_WIN32,ERROR_ALREADY_EXISTS)

#endif /* _P2P_H */

#ifdef DEFINE_GUID

#ifndef NO_P2P_GROUP
DEFINE_GUID(PEER_GROUP_ROLE_ADMIN,0x04387127,0xaa56,0x450a,0x8c,0xe5,0x4f,0x56,0x5c,0x67,0x90,0xf4);
DEFINE_GUID(PEER_GROUP_ROLE_MEMBER,0xf12dc4c7,0x0857,0x4ca0,0x93,0xfc,0xb1,0xbb,0x19,0xa3,0xd8,0xc2);
#if NTDDI_VERSION >= NTDDI_VISTA
DEFINE_GUID(PEER_GROUP_ROLE_INVITING_MEMBER,0x4370fd89,0xdc18,0x4cfb,0x8d,0xbf,0x98,0x53,0xa8,0xa9,0xf9,0x05);
#endif /* NTDDI_VERSION >= NTDDI_VISTA */
#endif /* NO_P2P_GROUP */

#ifndef NO_P2P_COLLABORATION
DEFINE_GUID(PEER_COLLAB_OBJECTID_USER_PICTURE,0xdd15f41f,0xfc4e,0x4922,0xb0,0x35,0x4c,0x06,0xa7,0x54,0xd0,0x1d);
#endif /* NO_P2P_COLLABORATION */

#endif /* DEFINE_GUID */
