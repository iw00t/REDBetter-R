#ifndef GROUP_VO
#define GROUP_VO

#include "BaseVO.h"

#include <string>
#include <vector>


namespace REDBetterR {
    namespace VO {
        class ReleaseVO : public BaseVO<ReleaseVO> {
        public:
            ReleaseVO& releaseArtist(const std::string & releaseArtist) {
                this->releaseArtistValue = releaseArtist;
                return *this;
            }
            ReleaseVO& releaseName(const std::string & releaseName) {
                this->releaseNameValue = releaseName;
                return *this;
            }
            ReleaseVO& releaseYear(const std::string & releaseYear) {
                this->releaseYearValue = releaseYear;
                return *this;
            }
            ReleaseVO& releaseUrl(const std::string & releaseUrl) {
                this->releaseUrlValue = releaseUrl;
                return *this;
            }
            ReleaseVO& media(const std::string & media) {
                this->mediaValue = media;
                return *this;
            }
            ReleaseVO& filePath(const std::string & filePath) {
                this->filePathValue = filePath;
                return *this;
            }
            ReleaseVO& fileList(const std::string & fileList) {
                this->fileListValue = fileList;
                return *this;
            }
            ReleaseVO& encoding(const std::string & encoding) {
                this->encodingValue = encoding;
                return *this;
            }
            ReleaseVO& remasterTitle(const std::string & remasterTitle) {
                this->remasterTitleValue = remasterTitle;
                return *this;
            }
            ReleaseVO& remasterYear(const std::string & remasterYear) {
                this->remasterYearValue = remasterYear;
                return *this;
            }
            ReleaseVO& remasterRecordLabel(const std::string & remasterRecordLabel) {
                this->remasterRecordLabelValue = remasterRecordLabel;
                return *this;
            }
            ReleaseVO& remasterCatalogueNumber(const std::string & remasterCatalogueNumber) {
                this->remasterCatalogueNumberValue = remasterCatalogueNumber;
                return *this;
            }
            ReleaseVO& missingFormats(const std::vector<std::string> & missingFormats) {
                this->missingFormatsValue = missingFormats;
            }

            std::string getReleaseArtist() {
                return this->releaseArtistValue;
            }
            std::string getReleaseName() {
                return this->releaseNameValue;
            }
            std::string getReleaseYear() {
                return this->releaseYearValue;
            }
            std::string getReleaseUrl() {
                return this->releaseUrlValue;
            }
            std::string getMedia() {
                return this->mediaValue;
            }
            std::string getFilePath() {
                return this->filePathValue;
            }
            std::string getFileList() {
                return this->fileListValue;
            }
            std::string getEncoding() {
                return this->encodingValue;
            }
            std::string getRemasterTitle() {
                return this->remasterTitleValue;
            }
            std::string getRemasterYear() {
                return this->remasterYearValue;
            }
            std::string getRemasterRecordLabel() {
                return this->remasterRecordLabelValue;
            }
            std::string getRemasterCatalogueNumber() {
                return this->remasterCatalogueNumberValue;
            }
            std::vector<std::string> getMissingFormats() {
                return this->missingFormatsValue;
            }

        private:
            std::string releaseArtistValue;
            std::string releaseNameValue;
            std::string releaseYearValue;
            std::string releaseUrlValue;
            std::string mediaValue;
            std::string filePathValue;
            std::string fileListValue;
            std::string encodingValue;
            std::string remasterTitleValue;
            std::string remasterYearValue;
            std::string remasterRecordLabelValue;
            std::string remasterCatalogueNumberValue;
            std::vector<std::string> missingFormatsValue;
        };
    }
}

#endif // GROUP_VO
