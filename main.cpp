#include <iostream>
#include <map>

void DrawTable(const std::map<std::string, std::vector<double>>&);

int main()
{
    std::vector<double> principles = {10.0, 8.1, 6.18, 4.24, 2.29, 0.31};
    std::vector<double> interestPaid = {0.10, 0.08, 0.06, 0.04, 0.02, 0.00};
    std::vector<double> principlePaid = {1.90, 1.92, 1.94, 1.96, 1.98, 0.31};
    std::vector<double> endingPayment = {2, 2, 2, 2, 2, 0.31};
    std::vector<double> paymentBalance = {8.10, 6.18, 4.24, 2.29, 0.31, 0.00};

    std::map<std::string, std::vector<double>>  info = {{"Principle", principles}, {"Interest Paid", interestPaid}, {"Principle Paid", principlePaid},
                                                        {"Final Payment", endingPayment}, {"Left to Pay", paymentBalance}};
    DrawTable(info);
    return 0;
}

void DrawTable(const std::map<std::string, std::vector<double>>& info)
{
    std::string underlines;
    unsigned long size;
//    https://cplusplus.com/forum/beginner/123379/
    for (const auto & pair : info)
    {
        std::string key = pair.first;
        std::vector<double> numbers = pair.second;
        size = numbers.size();

        // Creates headings
        std::cout << pair.first << ' ';

        // Creates underlines of headings
        for (int i = 0; i < key.size(); i++)
            underlines += '-';
        underlines += ' ';
    }
    std::cout << '\n' << underlines << '\n';
    for (unsigned long index = 0; index < size; index++)
    {
        for (const auto & pair : info)
        {
            std::cout << pair.second[index];
            for (int i = 0; i < (pair.first.size()); i++) // - number of places after decimal (add function)
                std::cout << ' ';

        }
        std::cout << '\n';
    }

}