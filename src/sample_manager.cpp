#include "sample_manager.h"

void SampleManager::addReporter(ISampleReporter reporter) {
    this->reporters.append(reporter);
}