# The problem is from https://school.programmers.co.kr/learn/courses/30/lessons/258712

def solution(friends, gifts):
    # Make gift table
    gift_table = []
    for i in range(len(friends)):
        sub_table = [0 for i in range(len(friends))]
        
        for j in range(len(gifts)):
            name = friends[i]
            gift = gifts[j]
            
            giver = gift.split(" ")[0]
            receiver = gift.split(" ")[1]
            
            if name == giver:
                receiver_idx = friends.index(receiver)  # Find receiver name in the friends list
                sub_table[receiver_idx] += 1    # Increase receiver count
            
        gift_table.append(sub_table)
    
    # Make gift index table
    index_table = []
    for i in range(len(friends)):
        sub_table = [0, 0, 0]   # Initialize sub table
        sub_table[0] = sum(gift_table[i])
        sub_table[1] = sum([gift_table[j][i] for j in range(len(gift_table))])
        sub_table[2] = sub_table[0] - sub_table[1]
        
        index_table.append(sub_table)
    
    # Compare a number of gifts
    final_table = [0 for i in range(len(friends))]
    for i in range(len(friends)):
        for j in range(len(friends)):
            if i == j:
                pass
            else:
                if gift_table[i][j] > gift_table[j][i]:
                    final_table[i] += 1
                elif gift_table[i][j] < gift_table[j][i]:
                    pass
                else:
                    if index_table[i][2] > index_table[j][2]:
                        final_table[i] += 1
                    else:
                        pass
            
    answer = max(final_table)
    
    return answer

if __name__ == "__main__":
    friends = ["muzi", "ryan", "frodo", "neo"]
    gifts = ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]
    
    answer = solution(friends, gifts)