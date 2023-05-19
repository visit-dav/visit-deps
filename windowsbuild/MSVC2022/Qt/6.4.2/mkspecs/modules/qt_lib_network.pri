QT.network.VERSION = 6.4.2
QT.network.name = QtNetwork
QT.network.module = Qt6Network
QT.network.libs = $$QT_MODULE_LIB_BASE
QT.network.ldflags = 
QT.network.includes = $$QT_MODULE_INCLUDE_BASE $$QT_MODULE_INCLUDE_BASE/QtNetwork
QT.network.frameworks = 
QT.network.bins = $$QT_MODULE_BIN_BASE
QT.network.plugin_types = networkaccess networkinformation tls
QT.network.depends =  core
QT.network.uses = 
QT.network.module_config = v2
QT.network.DEFINES = QT_NETWORK_LIB
QT.network.enabled_features = schannel ssl dtls ocsp opensslv11 http udpsocket networkproxy socks5 networkinterface networkdiskcache localserver dnslookup sspi topleveldomain openssl
QT.network.disabled_features = getifaddrs ipv6ifname securetransport sctp brotli gssapi
QT_CONFIG += schannel ssl dtls ocsp opensslv11 http udpsocket networkproxy socks5 networkinterface networkdiskcache localserver dnslookup sspi topleveldomain openssl
QT_MODULES += network

