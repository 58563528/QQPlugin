#ifndef FTPSHARESPLUGIN_GLOBAL_H
#define FTPSHARESPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef FTPSHARESPLUGIN_LIB
# define FTPSHARESPLUGIN_EXPORT Q_DECL_EXPORT
#else
# define FTPSHARESPLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // FTPSHARESPLUGIN_GLOBAL_H