#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Set
{
private:
    vector<T> elements;

public:
    Set() {}
    Set(const vector<T> &elems) : elements(elems) {}
    Set(const Set &other) : elements(other.elements) {}
    Set<T> Union(const Set &other) const
    {
        Set<T> result = *this;
        for (const auto &elem : other.elements)
        {
            if (!Contains(elem))
                result.elements.push_back(elem);
        }
        return result;
    }
    Set<T> Intersection(const Set &other) const
    {
        Set<T> result;
        for (const auto &elem : elements)
        {
            if (other.Contains(elem))
                result.elements.push_back(elem);
        }
        return result;
    }
    Set<T> Complement(const Set &universe) const
    {
        Set<T> result = universe;
        for (const auto &elem : elements)
        {
            result.Remove(elem);
        }
        return result;
    }
    Set<T> Difference(const Set &other) const
    {
        Set<T> result = *this;
        for (const auto &elem : other.elements)
        {
            result.Remove(elem);
        }
        return result;
    }
    bool Equals(const Set &other) const
    {
        if (elements.size() != other.elements.size())
            return false;
        for (const auto &elem : elements)
        {
            if (!other.Contains(elem))
                return false;
        }
        return true;
    }
    void CartesianProduct(const Set &other) const
    {
        for (const auto &elem1 : elements)
        {
            for (const auto &elem2 : other.elements)
            {
                cout << "(" << elem1 << ", " << elem2 << ") ";
            }
        }
        cout << endl;
    }
    void PowerSet() const
    {
        vector<vector<T>> powerSet;
        GeneratePowerSet(powerSet, elements, 0, {});
        for (const auto &subset : powerSet)
        {
            cout << "{ ";
            for (const auto &elem : subset)
            {
                cout << elem << " ";
            }
            cout << "} ";
        }
        cout << endl;
    }
    bool IsDistinct() const
    {
        vector<T> sortedElements = elements;
        sort(sortedElements.begin(), sortedElements.end());
        for (size_t i = 1; i < sortedElements.size(); ++i)
        {
            if (sortedElements[i] == sortedElements[i - 1])
                return false;
        }
        return true;
    }
    void Statistics() const
    {
        double sum = 0.0;
        double sumOfSquares = 0.0;
        vector<T> sortedElements = elements;
        sort(sortedElements.begin(), sortedElements.end());
        size_t size = sortedElements.size();
        for (const auto &elem : sortedElements)
        {
            sum += elem;
            sumOfSquares += elem * elem;
        }
        double mean = sum / size;
        double variance = (sumOfSquares / size) - (mean * mean);
        double stdDeviation = sqrt(variance);
        T median = (size % 2 == 0) ? (sortedElements[size / 2 - 1] + sortedElements[size / 2]) / 2 : sortedElements[size / 2];
        cout << "Mean: " << mean << endl;
        cout << "Variance: " << variance << endl;
        cout << "Standard Deviation: " << stdDeviation << endl;
        cout << "Median: " << median << endl;
    }
    void Add(const T &elem)
    {
        if (!Contains(elem))
            elements.push_back(elem);
    }
    void Remove(const T &elem)
    {
        auto it = find(elements.begin(), elements.end(), elem);
        if (it != elements.end())
            elements.erase(it);
    }
    bool Contains(const T &elem) const
    {
        return find(elements.begin(), elements.end(), elem) != elements.end();
    }
    Set &operator=(const Set &other)
    {
        if (this != &other)
        {
            elements = other.elements;
        }
        return *this;
    }
    Set operator+(const Set &other) const
    {
        return Union(other);
    }
    static Set FromVector(const vector<T> &vec)
    {
        return Set(vec);
    }
    static Set FromInitializerList(initializer_list<T> initList)
    {
        return Set(vector<T>(initList));
    }
    void Display() const
    {
        cout << "{ ";
        for (const auto &elem : elements)
        {
            cout << elem << " ";
        }
        cout << "}" << endl;
    }

private:
    void GeneratePowerSet(vector<vector<T>> &powerSet, const vector<T> &set, size_t index, vector<T> current) const
    {
        if (index >= set.size())
        {
            powerSet.push_back(current);
            return;
        }
        GeneratePowerSet(powerSet, set, index + 1, current);
        current.push_back(set[index]);
        GeneratePowerSet(powerSet, set, index + 1, current);
    }
};

int main()
{
    Set<int> set1 = Set<int>::FromInitializerList({1, 2, 3});
    Set<int> set2 = Set<int>::FromInitializerList({2, 3, 4});
    cout << "Set 1: ";
    set1.Display();
    cout << "Set 2: ";
    set2.Display();
    cout << "Union: ";
    (set1 + set2).Display();
    cout << "Intersection: ";
    set1.Intersection(set2).Display();
    cout << "Complement of Set 1 in Universal Set {1, 2, 3, 4}: ";
    set1.Complement(Set<int>::FromInitializerList({1, 2, 3, 4})).Display();
    cout << "Set Difference (Set 1 - Set 2): ";
    set1.Difference(set2).Display();
    cout << "Is Set 1 equals Set 2: " << (set1.Equals(set2) ? "True" : "False") << endl;
    cout << "Cartesian Product: ";
    set1.CartesianProduct(set2);
    cout << "Power Set of Set 1: ";
    set1.PowerSet();
    cout << "Is Set 1 distinct: " << (set1.IsDistinct() ? "True" : "False") << endl;
    cout << "Statistics of Set 1: " << endl;
    set1.Statistics();
    return 0;
}
