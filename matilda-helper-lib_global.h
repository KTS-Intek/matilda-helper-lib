#ifndef MATILDAHELPERLIB_GLOBAL_H
#define MATILDAHELPERLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MATILDAHELPERLIB_LIBRARY)
#  define MATILDAHELPERLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MATILDAHELPERLIBSHARED_EXPORT Q_DECL_IMPORT
#endif


#endif // MATILDAHELPERLIB_GLOBAL_H
