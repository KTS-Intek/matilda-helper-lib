#ifndef MATILDAHELPERLIB_H
#define MATILDAHELPERLIB_H

#include <QtCore/qglobal.h>

#if defined(MATILDAHELPERLIB_LIBRARY)
#  define MATILDAHELPERLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MATILDAHELPERLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

extern "C" MATILDAHELPERLIBSHARED_EXPORT int libVersion();

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *libAbout();



extern "C" MATILDAHELPERLIBSHARED_EXPORT int add4test(int a, int b);

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *convertInData2base64(char *inData, int intDataLen, bool ommitTrailingEquals);


extern "C" MATILDAHELPERLIBSHARED_EXPORT char *convert2local8bit(char *inData, int intDataLen, int inDataMode, int outDataMode);

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *convert2utf8(char *inData, int intDataLen, int inDataMode, int outDataMode);

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *compressData(char *inData, int intDataLen, int inDataMode, int outDataMode, int compressLevel);

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *decompressData(char *inData, int intDataLen, int inDataMode, int outDataMode);

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *getHashSumm(char *inData, int intDataLen, int inDataMode, int outDataMode, int alg);

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *getLastError();


QByteArray convertData(const int &inOutDataMode, const QByteArray &inData, const bool &isOutData, bool &ok);

#endif // MATILDAHELPERLIB_H
