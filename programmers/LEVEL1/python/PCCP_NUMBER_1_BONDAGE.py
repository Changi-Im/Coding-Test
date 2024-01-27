# The problem is from https://school.programmers.co.kr/learn/courses/30/lessons/250137

def solution(bandage, health, attacks):
    t, x, y = bandage[0], bandage[1], bandage[2]
    
    max_health = health
    total_time = 0
    success_time = 0
    
    attack_time = [attacks[i][0] for i in range(len(attacks))]
    damage = [attacks[i][1] for i in range(len(attacks))]
    
    while total_time <= max(attack_time):   # Finish the procedure right after the last attack time
        if total_time in attack_time:
            idx = attack_time.index(total_time)
            success_time = 0
            health -= damage[idx]
            
            if health <= 0:
                return -1
        else:
            success_time += 1
            if health < max_health:
                if success_time == t:
                    success_time = 0
                    health += (x + y)
                else:
                    health += x
            else:
                if success_time == t:
                    success_time = 0
                else:
                    pass
            
        if health > max_health: # Check if the current health is greater than the maximum health or not
            health = max_health
            
        total_time += 1
        
    return health


if __name__ == "__main__":
    bandage = [3, 2, 7]
    health = 20
    attacks = [[1, 15], [5, 16], [8, 6]]
    
    answer = solution(bandage, health, attacks)