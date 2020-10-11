#ifndef CARPI_QT_NETWORK_GLOBAL_H
#define CARPI_QT_NETWORK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NETWORK_LIBRARY)
#  define NETWORK_EXPORT Q_DECL_EXPORT
#else
#  define NETWORK_EXPORT Q_DECL_IMPORT
#endif

#endif //CARPI_QT_NETWORK_GLOBAL_H
