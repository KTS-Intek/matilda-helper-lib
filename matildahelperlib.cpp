#include "matildahelperlib.h"
#include <QByteArray>
#include <QString>
#include <QVariant>
#include <QCryptographicHash>
#include <stdio.h>
#include <QTextStream>
#include "matilda-helper-def.h"


QByteArray lastErr;

//--------------------------------------------------------------------------
extern "C" MATILDAHELPERLIBSHARED_EXPORT int libVersion()
{
    return 1;
}
//--------------------------------------------------------------------------
extern "C" MATILDAHELPERLIBSHARED_EXPORT char *libAbout()
{
    return QByteArray("(c) KTS Intek Ltd 2016,\nbohdan@kts-intek.com.ua\n").data();
}
//--------------------------------------------------------------------------

extern "C" MATILDAHELPERLIBSHARED_EXPORT int add4test(int a, int b)
{
    return a + b;
}

//--------------------------------------------------------------------------
extern "C" MATILDAHELPERLIBSHARED_EXPORT char *convertInData2base64(char *inData, int intDataLen, bool ommitTrailingEquals)
{
    return QByteArray(inData, intDataLen).toBase64( ommitTrailingEquals ? QByteArray::OmitTrailingEquals : QByteArray::KeepTrailingEquals ).data();
}
//--------------------------------------------------------------------------

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *convert2local8bit(char *inData, int intDataLen, int inDataMode, int outDataMode)
{
    lastErr.clear();
    bool ok;
    QByteArray arr = convertData(inDataMode, QByteArray(inData, intDataLen), false, ok);
    if(ok){
        arr = QString(arr).toLocal8Bit();
        arr = convertData(outDataMode, arr, true, ok);
    }
    if(!ok){
        lastErr = arr;
        return 0;
    }
    return arr.data();
}
//--------------------------------------------------------------------------
extern "C" MATILDAHELPERLIBSHARED_EXPORT char *convert2utf8(char *inData, int intDataLen, int inDataMode, int outDataMode)
{
    lastErr.clear();
    bool ok;
    QByteArray arr = convertData(inDataMode, QByteArray(inData, intDataLen), false, ok);
    if(ok){
        arr = QVariant(arr).toByteArray();
        arr = convertData(outDataMode, arr, true, ok);
    }
    if(!ok){
        lastErr = arr;
        return 0;
    }
    return arr.data();
}
//--------------------------------------------------------------------------
extern "C" MATILDAHELPERLIBSHARED_EXPORT char *compressData(char *inData, int intDataLen, int inDataMode, int outDataMode, int compressLevel)
{
    lastErr.clear();
    bool ok;
    QByteArray arr = convertData(inDataMode, QByteArray(inData, intDataLen), false, ok);
    if(ok){
        arr = qCompress(arr, compressLevel);
        arr = convertData(outDataMode, arr, true, ok);
    }
    if(!ok){
        lastErr = arr;
        return 0;
    }
    return arr.data();
}
//--------------------------------------------------------------------------
extern "C" MATILDAHELPERLIBSHARED_EXPORT char *decompressData(char *inData, int intDataLen, int inDataMode, int outDataMode)
{
    lastErr.clear();
    bool ok;
    QByteArray arr = convertData(inDataMode, QByteArray(inData, intDataLen), false, ok);
    if(ok){
        arr = qUncompress(arr);
        arr = convertData(outDataMode, arr, true, ok);
    }
    if(!ok){
        lastErr = arr;
        return 0;
    }
    return arr.data();
}
//--------------------------------------------------------------------------
extern "C" MATILDAHELPERLIBSHARED_EXPORT char *getHashSumm(char *inData, int intDataLen, int inDataMode, int outDataMode, int alg)
{
    lastErr.clear();
    bool ok;
    QByteArray arr = convertData(inDataMode, QByteArray(inData, intDataLen), false, ok);
    if(ok){
        if(alg >= CRYPTO_HSH_MD4 && alg <= CRYPTO_HSH_SHA3_512){
           arr = convertData(outDataMode, QCryptographicHash::hash(inData, static_cast<QCryptographicHash::Algorithm>(alg)), true, ok);
        }else{
            ok = false;
            arr = "unknown algorithm " + QByteArray::number(alg);
        }
    }
    if(!ok){
        lastErr = arr;
        return 0;
    }

    return arr.data();
}
//--------------------------------------------------------------------------

QByteArray convertData(const int &inOutDataMode, const QByteArray &inData, const bool &isOutData, bool &ok)
{
    ok = true;
    QByteArray outData;
    if(isOutData){
        switch(inOutDataMode){
        case INOUT_DATA_HEXTXT: outData = inData.toHex(); break;
        case INOUT_DATA_BASE64: outData = inData.toBase64(QByteArray::OmitTrailingEquals); break;
        case INOUT_DATA_PLAINTEXT: outData = inData; break;
        case INOUT_DATA_ZLIB_BASE64: outData = qCompress( inData, CMPRSS_LVL_9 ).toBase64(QByteArray::OmitTrailingEquals); break;
        default: ok = false; outData = "out data unknown key " + QByteArray::number(inOutDataMode); break;
        }
    }else{
        switch(inOutDataMode){
        case INOUT_DATA_HEXTXT: outData = QByteArray::fromHex(inData); break;
        case INOUT_DATA_BASE64: outData = QByteArray::fromBase64(inData); break;
        case INOUT_DATA_PLAINTEXT: outData = inData; break;
        case INOUT_DATA_ZLIB_BASE64: outData = QByteArray::fromBase64(qUncompress(inData )); break;
        default: ok = false; outData = "in data unknown key " + QByteArray::number(inOutDataMode); break;
        }
    }

    return outData;
}
//--------------------------------------------------------------------------

extern "C" MATILDAHELPERLIBSHARED_EXPORT char *getLastError()
{
    if(lastErr.isEmpty())
       return QByteArray("No error").data();
    return lastErr.data();
}
//--------------------------------------------------------------------------
