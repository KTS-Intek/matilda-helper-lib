#ifndef MATILDAHELPERDEF_H
#define MATILDAHELPERDEF_H

#define INOUT_DATA_PLAINTEXT        0
#define INOUT_DATA_BASE64           1
#define INOUT_DATA_HEXTXT           2
#define INOUT_DATA_ZLIB_BASE64      3//in = fromBase64( uncompress( inData ) ), out = toBase64( compress( outData, CMPRSS_LVL_9 ) )

#define CMPRSS_LVL_1                1//NO COMPRSSSN
#define CMPRSS_LVL_2                2
#define CMPRSS_LVL_3                3
#define CMPRSS_LVL_4                4
#define CMPRSS_LVL_5                5
#define CMPRSS_LVL_6                6
#define CMPRSS_LVL_7                7
#define CMPRSS_LVL_8                8
#define CMPRSS_LVL_9                9//HIGH COMPRSSN

#define CRYPTO_HSH_MD4              0
#define CRYPTO_HSH_MD5              1
#define CRYPTO_HSH_SHA1             2
#define CRYPTO_HSH_SHA224           3
#define CRYPTO_HSH_SHA256           4
#define CRYPTO_HSH_SHA386           5
#define CRYPTO_HSH_SHA512           6
#define CRYPTO_HSH_SHA3_224         7
#define CRYPTO_HSH_SHA3_256         8
#define CRYPTO_HSH_SHA3_384         9
#define CRYPTO_HSH_SHA3_512         10


#endif // MATILDAHELPERDEF_H
