#ifndef CARPI_QT_NETWORK_H
#define CARPI_QT_NETWORK_H

#ifdef NETWORK_LOADABLE
#include "Network_global.h"
#endif

#include <QWidget>
#include <QNetworkInterface>

#ifdef NETWORK_LOADABLE
QT_BEGIN_NAMESPACE
namespace Ui { class Network; }
QT_END_NAMESPACE
#endif

class Network : public QWidget
{
Q_OBJECT
private:
#ifdef NETWORK_LOADABLE
    Ui::Network *ui;
#endif

public:
    explicit Network(QWidget *parent = nullptr);
    ~Network() override;

    static QNetworkInterface findInterface(const QString& prefix);
    static QString getIP(const QString& prefix);
    static QString getMAC(const QString& prefix);
};

#ifdef NETWORK_LOADABLE
extern "C" {
    NETWORK_EXPORT int getDefaultIndex();
    NETWORK_EXPORT char* getName();
    NETWORK_EXPORT QWidget* create();
    NETWORK_EXPORT int getVersion();
    NETWORK_EXPORT QStringList getSettingsKeys();
    NETWORK_EXPORT QStringList getDependencies();
};
#endif

#endif //CARPI_QT_NETWORK_H
