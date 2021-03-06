#ifndef FUNC_SEARCHGOOGLEIMAGES_H
#define FUNC_SEARCHGOOGLEIMAGES_H

#include "SearchByImage.h"
#include <string>

class NetworkClient;

class SearchGoogleImages: public SearchByImage  {

    public:
        explicit SearchGoogleImages(const std::string& fileName);
protected:
    void run() override;
    static std::string base64EncodeCompat(const std::string& file);
};

#endif