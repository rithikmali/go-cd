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

def print_code(LinesList):

    for line in LinesList:
        line = line.strip('\n')
        print(line)
    print()


def algID(ListTkns):

    new_line = ''
    if( ListTkns[3] == '+' ):
        
        if( ListTkns[2] == '0' ):                    
            new_line = ListTkns[0] + ' = ' + ListTkns[4]
                        
        elif( ListTkns[4] == '0' ):
            new_line = ListTkns[0] + ' = ' + ListTkns[2]
                       
        else:
            new_line = ' '.join(ListTkns)
            
    elif( ListTkns[3] == '*' ):

        if( ListTkns[2] == '0' or ListTkns[4] == '0' ):
            new_line = ListTkns[0] + ' = ' + '0'
            
        elif( ListTkns[2] == '1' ):
            new_line = ListTkns[0] + ' = ' + ListTkns[4]
            
        elif( ListTkns[4] == '1' ):
            new_line = ListTkns[0] + ' = ' + ListTkns[2]
        
        else:
            new_line = ' '.join(ListTkns)
            
    elif( ListTkns[3] == '/' and (ListTkns[2] == '0' and ListTkns[3] != '0')):
        new_line = ListTkns[0] + ' = ' + '0'
            
    elif( ListTkns[3] == '&&'):
        
        if(ListTkns[2] == 'true'):
            new_line = ListTkns[0]+ ' = ' + ListTkns[4]

        elif(ListTkns[4] == 'true'):
            new_line = ListTkns[0]+ ' = '+ ListTkns[2]

        else:
            new_line = ' '.join(ListTkns)
    
    elif( ListTkns[3] == '||'):
        
        if(ListTkns[2] == 'false'):
            new_line = ListTkns[0]+ ' = '+ ListTkns[4]
            
        elif(ListTkns[4] == 'false'):
            new_line = ListTkns[0] + ' = ' + ListTkns[2]
            
        
        else:
            new_line = ' '.join(ListTkns)
            
    else:
        new_line = ' '.join(ListTkns)
        
    return new_line



def constantFP(LinesList):
    
    val1 = 1
    val2 = 1
    
    cf_list, val1 = constantFolding(LinesList)
    cp_list, val2 = constantProp(cf_list)
    while( val1 == 1 or val2 == 1):
        
        cf_list, val1 = constantFolding(cp_list,cf_list)
        cp_list, val2 = constantProp(cf_list,cp_list)
        
    return cp_list



def constantFolding(LinesList, comp=[]):
    f_list=[]
    for line in LinesList:
        line = line.strip('\n')
        ListTkns = line.split(' ')
        if(len(ListTkns) == 5):
            
            if( (ListTkns[3] in arith_op) and (is_num(ListTkns[2]) and is_num(ListTkns[4])) ):
                
                new_line = ListTkns[0]+ ' = '+ str(eval(ListTkns[2]+ListTkns[3]+ListTkns[4]))
                f_list.append(new_line)
                
            elif( (ListTkns[3] in logic_op) and (is_num(ListTkns[2]) and is_num(ListTkns[4])) ):
                
                new_line = ListTkns[0]+ ' = '+ str(eval(ListTkns[2]+ListTkns[3]+ListTkns[4]))
                f_list.append(new_line)
         
            else:
                
                if ( not (is_id(ListTkns[2]) and is_id(ListTkns[4])) ):
                    new_line = algID(ListTkns)
                    f_list.append(new_line) 
                    
                else:
                    f_list.append(line)
        else:
            f_list.append(line)
                    
    if( LinesList == comp ):
        return (f_list, 0)
    else:
        return (f_list, 1)

def constantProp(LinesList,comp=[]):
    temp = dict()    
    f_list = []
    for line in LinesList:
        
        line = line.strip('\n')
        ListTkns = line.split()
        if( len(ListTkns) == 3 and ListTkns[1] == '=' and is_num(ListTkns[2]) ):
            
            temp[ListTkns[0]] = ListTkns[2]
            new_line = ' '.join(ListTkns)
            f_list.append(new_line)
            
        elif( len(ListTkns) == 3 and ListTkns[1] == '=' and ListTkns[2] in temp ):
            
            new_line = ListTkns[0]+ ' = '+ temp[ListTkns[2]]
            f_list.append(new_line)
            
            temp[ListTkns[0]] = temp[ListTkns[2]]
                   
        elif( len(ListTkns) == 5 ):
            
            if( ListTkns[2] in temp ):
                ListTkns[2] = temp[ListTkns[2]]
                
            if( ListTkns[4] in temp ):
                ListTkns[4] = temp[ListTkns[4]]
                
            if( ListTkns[0] in temp ):
                temp.pop(ListTkns[0])
            
            new_line = ' '.join(ListTkns)
            f_list.append(new_line)
            
        else:
            
            f_list.append(line)      
    
    if(f_list == comp):
        return (f_list, 0)
    else:
        return (f_list, 1)
    
                
def strengthRed(LinesList, comp=[]):
    f_list = []
    for line in LinesList:
        
        line = line.strip('\n')
        ListTkns = line.split(' ')
        
        if( len(ListTkns) == 5 ):
            
            if( ListTkns[3] == '**' and ListTkns[4] == '2'):                
                new_line = ListTkns[0]+ ' = '+ ListTkns[2]+ ' * '+ ListTkns[2]
                f_list.append(new_line)
                
            elif( ListTkns[3] == '*' and ListTkns[4] == '2'):
                new_line = ListTkns[0]+ ' = '+ ListTkns[2]+ ' + '+ ListTkns[2]
                f_list.append(new_line)
            
            elif( ListTkns[3] == '/' and ListTkns[4] == '2'):
                new_line = ListTkns[0]+ ' = '+ ListTkns[2]+ ' >> '+ '1'
                f_list.append(new_line)
                            
            else:
                f_list.append(line)
        else:
            f_list.append(line)
        
    
    if(f_list == comp):
        return (f_list, 0)
    else:
        return (f_list, 1)
                            
            
def copyProp(LinesList, comp=[]):
    
    f_list = []
    temp = {}
    for line in LinesList:
        
        line = line.strip('\n')
        ListTkns = line.split(' ')
        
        if( len(ListTkns) == 3 ):
            if (ListTkns[2] not in temp) and (is_id(ListTkns[2]) or is_temp(ListTkns[2])):
                        
                temp[ListTkns[0]] = ListTkns[2]
                new_line = line
        
            elif( ListTkns[2] in temp ):
            
                ListTkns[2] = temp[ListTkns[2]]
                temp[ListTkns[0]] = temp[ListTkns[2]]
                
            if( '[' in ListTkns[2] ):
                
                t = ListTkns[2]
                t = t.split('[')[1]
                t = t.split(']')[0]
                
                if( t in temp ):
                    ListTkns[2] = ListTkns[2].replace(t, temp[t])
                
            if( '[' in ListTkns[0] ):
                t = ListTkns[0]
                t = t.split('[')[1]
                t = t.split(']')[0]
                
                if( t in temp ):
                    ListTkns[0] = ListTkns[0].replace(t, temp[t])
                
            new_line = ' '.join(ListTkns)
            f_list.append(new_line)
                
        
        elif( len(ListTkns) == 5 ):
            
            if( ListTkns[2] in temp ):                
                ListTkns[2] = temp[ListTkns[2]]
                
            if( ListTkns[4] in temp ):                
                ListTkns[4] = temp[ListTkns[4]]
                
            if( ListTkns[0] in temp ):
                temp.pop(ListTkns[0])
            
            new_line = ' '.join(ListTkns)
            f_list.append(new_line)
        
        elif( len(ListTkns) == 4):
            if ( ListTkns[1] in temp ):
                ListTkns[1] = temp[ListTkns[1]]
            new_line = ' '.join(ListTkns)
            f_list.append(new_line)

        else:    
            f_list.append(line)
    
    if( f_list == comp ):
        return (f_list, 0)
    else:
        return (f_list, 1)

    

def variableAssgnCheck(LinesList, token, line_no):
    

    for line in LinesList[line_no + 1: ]:
        
        line = line.strip('\n')
        ListTkns = line.split()
        
        if(token in ListTkns[0]):
            match1 = line + '\n'
            break
            
        else:
            match1 = 'none'
            
            
    for line in LinesList[line_no + 1: ]:
        
        line = line.strip('\n')
        ListTkns = line.split()
        
        if( len(ListTkns) == 3 and (token in ListTkns[2]) ):
            match2 = line + '\n'
            break
        
        
        elif( len(ListTkns) == 5 and ( token == ListTkns[2] or token == ListTkns[4]) ):
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
            
            i1 = LinesList[line_no+1: ].index(match1)
            i2 = LinesList[line_no+1: ].index(match2)
            if( i1 < i2 ):
                return 1
            else:
                return 0
                
def deadCodeRemove(LinesList):
    
    f_list = []
    skip_next = False
    for i, line in enumerate(LinesList[:-1]):
        
        line = line.strip('\n')
        ListTkns = line.split()
        
        if( len(ListTkns) == 3 and ListTkns[1] == '=' and (is_num(ListTkns[2]) or is_bool(ListTkns[2])) ):
            pass
        
        elif( len(ListTkns) == 3 and re.match('[a-zA-z]\w*\[[a-zA-Z]\w*\]', ListTkns[0]) ):
            f_list.append(line)
            
        elif( len(ListTkns) == 3 and ListTkns[1] == '=' ):
            
            flag = variableAssgnCheck(LinesList, ListTkns[0], i)
            
            if (flag == 1):
                pass
            else:
                f_list.append(line)
        
        else:
            
            # if(len(ListTkns) == 4 and ListTkns[1]=='True'):
            #     pass
            # else:
                f_list.append(line)
            
    f_list.append(LinesList[-1])
    # for i, line in enumerate(f_list[:-1]):
    #     line = line.strip('\n')
    #     ListTkns = line.split()
    #     if(skip_next):
    #             pass
    #     if(len(ListTkns) == 4 and ListTkns[1]=='True'):
    #         line = line.strip('\n')
    #         ListTkns = line.split()
    #             pass
    #         else:
    return f_list



if( __name__ == '__main__'):
    
    filename = 'co_test.txt'
    f = open(filename, 'r')

    LinesList = f.readlines()
    print('-'*27,"ICG" , '-'*27)
    print_code(LinesList)

    sr_list, flagsr = strengthRed(LinesList)
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