//
// Created by paul on 4/4/2021.
//

#ifndef A67_PAULADAM2001_FILEREPOSITORY_H
#define A67_PAULADAM2001_FILEREPOSITORY_H

#include "repository.h"
#include "trenchCoat.h"
#include <string>


class FileRepository: public Repository {
private:

    string fileName;

    void write_in_file();

    vector<trenchCoat> load_from_file();

public:

//    FileRepository();

    explicit FileRepository(string fileName);

//    bool create_file(const string& file_name);

//    vector<trenchCoat> getDynArr();

    void add_repo(const string& size, const string& color, int price, int quantity, const string& photograph) override;

    void delete_repo(const string& size, const string& color, const string& photograph) override;

    void update_price_repo(const string& size, const string& color, int price, const string& photograph) override;

    void update_quantity_repo(const string& size, const string& color, int quantity, const string& photograph) override;

    int search_in_repository(const string& size, const string& color, const string& photograph) override;

    vector<trenchCoat> getDynArr() override;

    ~FileRepository() override;
};


#endif //A67_PAULADAM2001_FILEREPOSITORY_H
