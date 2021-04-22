#!/usr/bin/env python
# coding: utf-8

import re

arith_op = ['+','-','*','/']
logic_op = ['<','>','<=','>=','==','!=']
rel_op = ['&&','||']
keywords = ['IF','FALSE','GOTO','print']
is_level = lambda s : bool(re.match(r"^L[0-9]*$", s)) 
is_temp = lambda s : bool(re.match(r"^T[0-9]*$", s)) 
is_id = lambda s : bool(re.match(r"^[A-Za-z][A-Za-z0-9_]*$", s)) 
is_num = lambda s: bool(re.match(r"^[0-9]*(\.)?[0-9]*$", s))
is_bool = lambda s: bool(re.match(r"^(true|false)$", s))

def print_code(list_of_lines):

    for line in list_of_lines:
        line = line.strip('\n')
        print(line)
    print()


def algID(tokens):
    '''
    Checks if it expression is algebric identity in the ICG
    eg.
    BEFORE:
        T1 = x + 0
        T3 = 0 * x
        T5 = x && true
    AFTER:
        T1 = x
        T3 = 0
        T5 = x
    '''

    new_line = ''
    if( tokens[3] == '+' ):
        
        if( tokens[2] == '0' ):                    
            new_line = tokens[0] + ' = ' + tokens[4]
                        
        elif( tokens[4] == '0' ):
            new_line = tokens[0] + ' = ' + tokens[2]
                       
        else:
            new_line = ' '.join(tokens)
            
    elif( tokens[3] == '*' ):

        if( tokens[2] == '0' or tokens[4] == '0' ):
            new_line = tokens[0] + ' = ' + '0'
            
        elif( tokens[2] == '1' ):
            new_line = tokens[0] + ' = ' + tokens[4]
            
        elif( tokens[4] == '1' ):
            new_line = tokens[0] + ' = ' + tokens[2]
        
        else:
            new_line = ' '.join(tokens)
            
    elif( tokens[3] == '/' and (tokens[2] == '0' and tokens[3] != '0')):
        new_line = tokens[0] + ' = ' + '0'
            
    elif( tokens[3] == '&&'):
        
        if(tokens[2] == 'true'):
            new_line = tokens[0]+ ' = ' + tokens[4]

        elif(tokens[4] == 'true'):
            new_line = tokens[0]+ ' = '+ tokens[2]

        else:
            new_line = ' '.join(tokens)
    
    elif( tokens[3] == '||'):
        
        if(tokens[2] == 'false'):
            new_line = tokens[0]+ ' = '+ tokens[4]
            
        elif(tokens[4] == 'false'):
            new_line = tokens[0] + ' = ' + tokens[2]
            
        
        else:
            new_line = ' '.join(tokens)
            
    else:
        new_line = ' '.join(tokens)
        
    return new_line



def constantFP(list_of_lines):
    
    val1 = 1
    val2 = 1
    
    cf_list, val1 = constantFolding(list_of_lines)
    cp_list, val2 = constantProp(cf_list)
    
    
    while( val1 == 1 or val2 == 1):
        
        cf_list, val1 = constantFolding(cp_list,cf_list)
        cp_list, val2 = constantProp(cf_list,cp_list)
        
    return cp_list



def constantFolding(list_of_lines, comp=[]):
    
    f_list=[]
    for line in list_of_lines:
        line = line.strip('\n')
        tokens = line.split(' ')
        if(len(tokens) == 5):
            
            if( (tokens[3] in arith_op) and (is_num(tokens[2]) and is_num(tokens[4])) ):
                
                new_line = tokens[0]+ ' = '+ str(eval(tokens[2]+tokens[3]+tokens[4]))
                f_list.append(new_line)
                
            elif( (tokens[3] in logic_op) and (is_num(tokens[2]) and is_num(tokens[4])) ):
                
                new_line = tokens[0]+ ' = '+ str(eval(tokens[2]+tokens[3]+tokens[4]))
                f_list.append(new_line)
         
            else:
                
                if ( not (is_id(tokens[2]) and is_id(tokens[4])) ):
                    new_line = algID(tokens)
                    f_list.append(new_line) 
                    
                else:
                    f_list.append(line)
        else:
            f_list.append(line)
                    
    if( list_of_lines == comp ):
        return (f_list, 0)
    else:
        return (f_list, 1)



def constantProp(list_of_lines,comp=[]):

    
    temp = dict()    
    f_list = []
    for line in list_of_lines:
        
        line = line.strip('\n')
        tokens = line.split()
        if( len(tokens) == 3 and tokens[1] == '=' and is_num(tokens[2]) ):
            
            temp[tokens[0]] = tokens[2]
            new_line = ' '.join(tokens)
            f_list.append(new_line)
            
        elif( len(tokens) == 3 and tokens[1] == '=' and tokens[2] in temp ):
            
            new_line = tokens[0]+ ' = '+ temp[tokens[2]]
            f_list.append(new_line)
            
            temp[tokens[0]] = temp[tokens[2]]
                   
        elif( len(tokens) == 5 ):
            
            if( tokens[2] in temp ):
                tokens[2] = temp[tokens[2]]
                
            if( tokens[4] in temp ):
                tokens[4] = temp[tokens[4]]
                
            if( tokens[0] in temp ):
                temp.pop(tokens[0])
            
            new_line = ' '.join(tokens)
            f_list.append(new_line)
            
        else:
            
            f_list.append(line)      
    
    if(f_list == comp):
        return (f_list, 0)
    else:
        return (f_list, 1)
    
                
def strengthRed(list_of_lines, comp=[]):
    
    f_list = []
    for line in list_of_lines:
        
        line = line.strip('\n')
        tokens = line.split(' ')
        
        if( len(tokens) == 5 ):
            
            if( tokens[3] == '**' and tokens[4] == '2'):                
                new_line = tokens[0]+ ' = '+ tokens[2]+ ' * '+ tokens[2]
                f_list.append(new_line)
                
            elif( tokens[3] == '*' and tokens[4] == '2'):
                new_line = tokens[0]+ ' = '+ tokens[2]+ ' + '+ tokens[2]
                f_list.append(new_line)
            
            elif( tokens[3] == '/' and tokens[4] == '2'):
                new_line = tokens[0]+ ' = '+ tokens[2]+ ' >> '+ '1'
                f_list.append(new_line)
                            
            else:
                f_list.append(line)
        else:
            f_list.append(line)
        
    
    if(f_list == comp):
        return (f_list, 0)
    else:
        return (f_list, 1)
                            
            
def copyProp(list_of_lines, comp=[]):
    
    f_list = []
    temp = {}
    for line in list_of_lines:
        
        line = line.strip('\n')
        tokens = line.split(' ')
        
        if( len(tokens) == 3 ):
            if (tokens[2] not in temp) and (is_id(tokens[2]) or is_temp(tokens[2])):
                        
                temp[tokens[0]] = tokens[2]
                new_line = line
        
            elif( tokens[2] in temp ):
            
                tokens[2] = temp[tokens[2]]
                temp[tokens[0]] = temp[tokens[2]]
                
            if( '[' in tokens[2] ):
                
                t = tokens[2]
                t = t.split('[')[1]
                t = t.split(']')[0]
                
                if( t in temp ):
                    tokens[2] = tokens[2].replace(t, temp[t])
                
            if( '[' in tokens[0] ):
                t = tokens[0]
                t = t.split('[')[1]
                t = t.split(']')[0]
                
                if( t in temp ):
                    tokens[0] = tokens[0].replace(t, temp[t])
                
            new_line = ' '.join(tokens)
            f_list.append(new_line)
                
        
        elif( len(tokens) == 5 ):
            
            if( tokens[2] in temp ):                
                tokens[2] = temp[tokens[2]]
                
            if( tokens[4] in temp ):                
                tokens[4] = temp[tokens[4]]
                
            if( tokens[0] in temp ):
                temp.pop(tokens[0])
            
            new_line = ' '.join(tokens)
            f_list.append(new_line)
        
        elif( len(tokens) == 4):
            if ( tokens[1] in temp ):
                tokens[1] = temp[tokens[1]]
            new_line = ' '.join(tokens)
            f_list.append(new_line)

        else:    
            f_list.append(line)
    
    if( f_list == comp ):
        return (f_list, 0)
    else:
        return (f_list, 1)

    

def variableAssgnCheck(list_of_lines, token, line_no):
    

    for line in list_of_lines[line_no + 1: ]:
        
        line = line.strip('\n')
        tokens = line.split()
        
        if(token in tokens[0]):
            match1 = line + '\n'
            break
            
        else:
            match1 = 'none'
            
            
    for line in list_of_lines[line_no + 1: ]:
        
        line = line.strip('\n')
        tokens = line.split()
        
        if( len(tokens) == 3 and (token in tokens[2]) ):
            match2 = line + '\n'
            break
        
        
        elif( len(tokens) == 5 and ( token == tokens[2] or token == tokens[4]) ):
            match2 = line + '\n'
            break
        else:
             match2 = 'none'
             
    

    if( match2 == 'none' ):
        return 1
    else:
             
        if( match1 == 'none'):
            return 0
             
        else:
            
            i1 = list_of_lines[line_no+1: ].index(match1)
            i2 = list_of_lines[line_no+1: ].index(match2)
            if( i1 < i2 ):
                return 1
            else:
                return 0
         
    


def deadCodeRemove(list_of_lines):
    
    f_list = []
    skip_next = False
    for i, line in enumerate(list_of_lines[:-1]):
        
        line = line.strip('\n')
        tokens = line.split()
        
        if( len(tokens) == 3 and tokens[1] == '=' and (is_num(tokens[2]) or is_bool(tokens[2])) ):
            pass
        
        elif( len(tokens) == 3 and re.match('[a-zA-z]\w*\[[a-zA-Z]\w*\]', tokens[0]) ):
            f_list.append(line)
            
        elif( len(tokens) == 3 and tokens[1] == '=' ):
            
            flag = variableAssgnCheck(list_of_lines, tokens[0], i)
            
            if (flag == 1):
                pass
            else:
                f_list.append(line)
        
        else:
            
            # if(len(tokens) == 4 and tokens[1]=='True'):
            #     pass
            # else:
                f_list.append(line)
            
    f_list.append(list_of_lines[-1])
    # for i, line in enumerate(f_list[:-1]):
    #     line = line.strip('\n')
    #     tokens = line.split()
    #     if(skip_next):
    #             pass
    #     if(len(tokens) == 4 and tokens[1]=='True'):
    #         line = line.strip('\n')
    #         tokens = line.split()
    #             pass
    #         else:
    return f_list



if( __name__ == '__main__'):
    
    filename = 'icg_test2.txt'
    f = open(filename, 'r')

    list_of_lines = f.readlines()
    print('-'*27,"ICG" , '-'*27)
    print_code(list_of_lines)

    sr_list, flagsr = strengthRed(list_of_lines)
    print('-'*17,'Strength Reduction Done', '-'*17)
    print_code(sr_list)
    
    fp_list = constantFP(sr_list)        
    print('-'*5,'Constant Propagation and Constant Folding Done', '-'*5)
    print_code(fp_list)

    cp_list, flagcp = copyProp(fp_list)
    print('-'*20,'Copy Propagation Done', '-'*20)
    print_code(cp_list)

    dce_list = deadCodeRemove(cp_list)
    print('-'*19,'Dead Code Elimination Done', '-'*19)
    print_code(dce_list)