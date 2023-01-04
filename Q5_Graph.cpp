#include <iostream>
#include <unordered_map>
#include <vector>

// Data structure to represent a process
struct Process {
    int id;
    std::vector<int> resources;
};

// Data structure to represent a resource
struct Resource {
    int id;
    int count;
};

// Check if it is safe to allocate the given resource to the given process
bool isSafe(std::vector<Process> processes, std::vector<Resource> resources,
            std::unordered_map<int, int> allocation, int p, int r)
{
    // get the resources that are currently allocated to the process
    std::vector<int> allocated = processes[p].resources;

    // check if the process has already acquired the given resource
    if (std::find(allocated.begin(), allocated.end(), r) != allocated.end())
        return true;

    // check if the resource is available
    if (resources[r].count == 0)
        return false;

    // allocate the resource temporarily to the process
    resources[r].count--;
    allocated.push_back(r);
    processes[p].resources = allocated;

    // check if the process can acquire all its required resources
    bool canAcquire = true;
    for (int i = 0; i < processes.size(); i++) {
        for (int j = 0; j < processes[i].resources.size(); j++) {
            if (!isSafe(processes, resources, allocation, i, processes[i].resources[j])) {
                canAcquire = false;
                break;
            }
        }
    }

    // roll back the temporary allocation
    allocated.erase(std::remove(allocated.begin(), allocated.end(), r), allocated.end());
    resources[r].count++;
    processes[p].resources = allocated;

    return canAcquire;
}

int main()
{
    // create a set of processes and resources
    std::vector<Process> processes = {
        {0, {0, 1}}, {1, {1, 2}}, {2, {0, 2}}
    };
    std::vector<Resource> resources = {
        {0, 1}, {1, 1}, {2, 1}
    };

    // map to store the current allocation of resources to processes
    std::unordered_map<int, int> allocation;

    // allocate resources to processes
    for (int i = 0; i < processes.size(); i++) {
        for (int j = 0; j < processes[i].resources.size(); j++) {
            int r = processes[i].resources[j];
            if (!isSafe(processes, resources, allocation, i, r)) {
                std::cout << "Allocation is not safe" << std::endl;
                return 0;
            }
            allocation[r] = i;
        }
    }

    std::cout << "Allocation is safe" << std::endl;

    return 0;
}