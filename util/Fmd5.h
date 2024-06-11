
#ifndef FMD5_H
#define FMD5_H

#include <iostream>
#include <fstream>
#include <openssl/md5.h>
#include <openssl/evp.h>

struct Fmd5
{
    static std::string str_to_md5(const std::string &str)
    {
        std::string ret_md5;
        const EVP_MD *md = EVP_md5();
        unsigned int len_md = EVP_MD_get_size(md);
        EVP_MD_CTX *ctx = EVP_MD_CTX_new();

        if(EVP_DigestInit(ctx,md))
        {
            if(EVP_DigestUpdate(ctx,str.c_str(),str.size()))
            {
                unsigned char buf[len_md] = {0};
                if(EVP_DigestFinal(ctx,buf,nullptr))
                {
                    ret_md5 = std::string((char*)buf,len_md);
                }
            }
        }
        EVP_MD_CTX_free(ctx);
        return ret_md5;
    }

    static std::string file_to_md5(const std::string &filename)
    {
        std::string ret_md5;
        const EVP_MD *md = EVP_md5();
        unsigned int len_md = EVP_MD_get_size(md);
        EVP_MD_CTX *ctx = EVP_MD_CTX_new();

        if(EVP_DigestInit(ctx,md))
        {
            std::ifstream fs(filename);
            if(fs.is_open())
            {
                std::string sline;
                while(std::getline(fs,sline))
                {
                    if(!EVP_DigestUpdate(ctx,sline.c_str(),sline.size()))
                    {   
                        return "";
                    }
                }
                unsigned char buf[len_md] = {0};
                if(EVP_DigestFinal(ctx,buf,nullptr))
                {
                    ret_md5 = std::string((char*)buf,len_md);
                }
                fs.close();
            }
        }
        EVP_MD_CTX_free(ctx);
        return ret_md5;
    }
};
#endif // FMD5_H
