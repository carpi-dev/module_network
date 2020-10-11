#include "Network.h"

#ifdef NETWORK_LOADABLE
#include "ui_network.h"
#endif

Network::Network(QWidget *parent): QWidget(parent),
#ifdef NETWORK_LOADABLE
ui(new Ui::Network)
#endif
{
#ifdef NETWORK_LOADABLE
    ui->setupUi(this);
#endif
    // todo signals and slots for labels
}

Network::~Network()
{
#ifdef NETWORK_LOADABLE
    delete ui;
#endif
}

QNetworkInterface Network::findInterface(const QString& prefix) {
    for(const QNetworkInterface& i : QNetworkInterface::allInterfaces()){
        if(i.name().startsWith(prefix)) return i;
    }
    return QNetworkInterface();
}

QString Network::getIP(const QString &prefix) {
    auto nif = findInterface(prefix);
    if(nif.isValid() && !nif.addressEntries().isEmpty()) {
        return nif.addressEntries().first().ip().toString();
    }
    return "";
}

QString Network::getMAC(const QString &prefix) {
    auto nif = findInterface(prefix);
    if(nif.isValid()) return nif.hardwareAddress();
    return "";
}


#ifdef NETWORK_LOADABLE
extern "C" NETWORK_EXPORT QWidget* create() {
    return new Network();
}

extern "C" NETWORK_EXPORT char* getName() {
    return (char*) "Network";
}

extern "C" NETWORK_EXPORT int getDefaultIndex(){
    return -1;
}

extern "C" NETWORK_EXPORT QStringList getSettingsKeys(){
    return QStringList(); // << KEY_SOMETHING_SOMETHING
}

extern "C" NETWORK_EXPORT QStringList getDependencies(){
    return QStringList();
}

extern "C" NETWORK_EXPORT int getVersion(){
    return 1;
}
#endif
