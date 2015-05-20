class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if (m_pData == object.m_pData) {
            return *this;
        }
        if (object.m_pData == nullptr) {
            delete [] m_pData;
            m_pData = nullptr;
            return *this;
        }
        int len = strlen(object.m_pData);
        char *new_pData = new char[len + 1];
        strncpy(new_pData, object.m_pData, len);
        delete [] m_pData;
        m_pData = new_pData;
        return *this;
    }
};
