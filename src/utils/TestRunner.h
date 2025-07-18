#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <string>
#include <vector>

class TestRunner {
public:
    TestRunner(const std::string& testFilePath);
    void runTests();

private:
    std::string testFilePath;
    void runStackTests();
    void runQueueTests();
    void runTreeTests();
    void runGraphTests();
    void runSortingTests();
};

#endif // TEST_RUNNER_H