/*
����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��

ʾ��:

����: "25525511135"
���: ["255.255.11.135", "255.255.111.35"]
*/ 
/*
���ݵ�˼�룬��dfs�е��񣬲�ͬ���ڻ��ݵ�ʱ����һ����֧�е�visit������dfs������ȫ�ֵ�visit��
��
�ڷ���һ����Ԫ�ؽ����µĵݹ����ʱ����Ҫ����Ԫ�ر��Ϊ�Ѿ����ʣ����������ڼ����ݹ����ʱ�����ظ����ʸ�Ԫ�أ�
�����ڵݹ鷵��ʱ����Ҫ��Ԫ�ر��Ϊδ���ʣ���Ϊֻ��Ҫ��֤��һ���ݹ����в�ͬʱ����һ��Ԫ�أ����Է����Ѿ����ʹ����ǲ��ڵ�ǰ�ݹ����е�Ԫ�ء�
�����������������ÿ������һ����

��ͨ DFS ��Ҫ���� �ɴ������� ����������ֻ��Ҫִ�е��ص��λ��Ȼ�󷵻ؼ��ɡ�
�� Backtracking ��Ҫ������� ������� ���⣬������ { 'a','b','c' } �����ַ���
����������������ַ����еõ����ַ���������������ִ�е��ض���λ�÷���֮�󻹻����ִ�������̡� 
������Ҳ������������⣩ 
*/
class Solution {
public:
    int findDot(string str)
    {
        size_t index = str.find(".", index);
        int count = 0;
        while( index != str.npos)
        {
            count++;
            index = str.find(".", index + 1);
            
        }
        
        return count;
    }
    
    void bt(vector<string>& ans, string pre, string s)
    {
        int dotNum = findDot(pre);
        
        //�����ּӵ������Բ����ں���
        int curIndex = pre.length() - dotNum;
        
        //�Ѿ���3����
        if(dotNum == 3)
        {
            //���ȹ���
            if(pre.length() == s.length() + 3)
                ans.push_back(pre);
            else
                return;
        }
        else     //����ӵ�,һ��ʼΪ�յ�ʱ�򲻼�
        {
            if(pre != "")
                pre += ".";
        }
        
        //Ҫ����dotNum
        
        
        //���3λ 0-255.����Ƿ�Խ��
        for(int i = 1; i <= min(3, (int)(s.length() - curIndex)); i++)
        {
            //��ȥ�������ǲ��Ǵ���255
            string temp = s.substr(curIndex, i);
            if(atoi(temp.c_str()) > 255)
                break;
            
            //������ǰ����
            if(temp.length() != 1 && temp[0] == '0')
                break;
            
            //���ﲻ��ֱ����pre�������Ӱ����һ��
            string tempPre = pre + temp;
            //pre += temp;
            bt(ans, tempPre, s);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        bt(ans, "", s);
        return ans;
    }
};
