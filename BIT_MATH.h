
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  SET_BIT(REG,BIT)      (REG=REG|(1<<BIT))
#define  CLEAR_BIT(REG,BIT)    (REG=REG&~(1<<BIT))
#define  TOGGLE_BIT(REG,BIT)    (REG=REG^(1<<BIT))
#define  GET_BIT(REG,BIT)      ((REG>>BIT)&1)




#endif /* BIT_MATH_H_ */