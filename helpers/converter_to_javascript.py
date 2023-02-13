# Copyright Fernando Pelliccioni 2016-2023
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

import re


code = """
# cost = 18
# n_nodes = 302864
# version = 1.4
# time = 549.450
# hash_table_size = 3276800
# n_solved = 18047
# n_unsolved = 259823
# n_hits = 3542630
# n_misses = 1921445
# avg_priority = 248.208
# avg_cost = 5.588

# n=11, i=6, cost=18: no comparisons done
find_1(a,b,c,d,e,f,g,h,i,j,k) =
  if a > b
  then find_2(c,d,e,f,g,h,i,j,k,a,b)
  else find_2(c,d,e,f,g,h,i,j,k,b,a)
# n=11, i=6, cost=17: j>k
find_2(a,b,c,d,e,f,g,h,i,j,k) =
  if a > b
  then find_3(c,d,e,f,g,h,i,a,j,k,b)
  else find_3(c,d,e,f,g,h,i,b,j,k,a)
# n=11, i=6, cost=16: h>k,i>j
find_3(a,b,c,d,e,f,g,h,i,j,k) =
  if a > b
  then find_4(c,d,e,f,g,a,h,i,j,k,b)
  else find_4(c,d,e,f,g,b,h,i,j,k,a)
# n=11, i=6, cost=15: f>k,g>j,h>i
find_4(a,b,c,d,e,f,g,h,i,j,k) =
  if a > b
  then find_5(c,d,e,a,f,g,h,i,j,k,b)
  else find_5(c,d,e,b,f,g,h,i,j,k,a)
# n=11, i=6, cost=14: d>k,e>j,f>i,g>h
find_5(a,b,c,d,e,f,g,h,i,j,k) =
  if a > b
  then find_6(c,a,d,e,f,g,h,i,j,k,b)
  else find_6(c,b,d,e,f,g,h,i,j,k,a)
# n=11, i=6, cost=13: b>k,c>j,d>i,e>h,f>g
find_6(a,b,c,d,e,f,g,h,i,j,k) =
  if b > c
  then find_7(a,d,e,f,b,g,h,i,k,c,j)
  else find_7(a,d,e,f,c,g,h,i,j,b,k)
# n=11, i=6, cost=12: b>h,c>g,d>f,e>i,e>j,j>k
find_7(a,b,c,d,e,f,g,h,i,j,k) =
  if b > c
  then find_8(a,d,b,e,f,i,h,j,c,k,g)
  else find_8(a,d,c,e,f,i,g,j,b,k,h)
# n=11, i=6, cost=11: b>e,c>g,c>i,d>f,d>h,h>j,i>k
find_8(a,b,c,d,e,f,g,h,i,j,k) =
  if h > i
  then find_9(a,b,c,d,f,g,e,h,j,i,k)
  else find_9(a,b,d,c,g,f,e,i,k,h,j)
# n=11, i=6, cost=10: b>g,c>f,c>j,d>e,d>h,h>i,h>j,j>k
find_9(a,b,c,d,e,f,g,h,i,j,k) =
  if a > e
  then find_10(b,a,c,d,f,g,h,e,i,j,k)
  else find_11(b,e,c,h,i,f,a,g,j,k)
# n=10, i=5, cost=9: a>h,b>g,c>f,c>i,d>e,d>i,i>j
find_11(a,b,c,d,e,f,g,h,i,j) =
  if a > b
  then find_12(c,d,a,e,f,h,b,g,i,j)
  else find_12(c,d,b,e,f,g,a,h,i,j)
# n=10, i=5, cost=8: a>e,a>i,b>d,b>i,c>f,c>g,g>h,i>j
find_12(a,b,c,d,e,f,g,h,i,j) =
  if d > e
  then find_13(a,c,b,f,g,d,h,i,e,j)
  else find_13(b,c,a,f,g,e,h,i,d,j)
# n=10, i=5, cost=7: a>h,a>i,b>d,b>e,c>f,c>h,e>g,f>i,h>j
find_13(a,b,c,d,e,f,g,h,i,j) =
  if d > f
  then find_14(a,c,b,e,d,g,h,f,j)
  else find_15(b,a,c,e,f,g,h,d,i,j)
# n=10, i=5, cost=6: a>d,a>h,b>g,b>i,c>e,c>g,d>f,e>h,e>i,g>j
find_15(a,b,c,d,e,f,g,h,i,j) =
  if d > g
  then find_16(b,a,c,d,e,f,h,i,g)
  else find_17(a,e,b,g,i,h,j,d)
# n=8, i=4, cost=5: a>f,a>h,b>e,b>f,c>d,c>e,d>g,d>h
find_17(a,b,c,d,e,f,g,h) =
  if a > b
  then find_18(a,c,d,b,g,f,e,h)
  else find_19(b,c,d,a,e,g,f)
# n=7, i=4, cost=4: a>d,a>e,b>c,b>e,c>f,d>g
find_19(a,b,c,d,e,f,g) =
  if c > d
  then find_20(a,c,f,e,d)
  else find_20(b,d,g,e,c)
# n=5, i=3, cost=3: a>d,a>e,b>c,b>e
find_20(a,b,c,d,e) =
  if c > d
  then find_21(c,a,e)
  else find_21(d,b,e)
# n=3, i=2, cost=2: b>c
find_21(a,b,c) =
  if a > b
  then b
  else find_22(a,c)
# n=2, i=1, cost=1: no comparisons done
find_22(a,b) =
  if a > b
  then a
  else b
# n=8, i=4, cost=4: a>d,a>h,b>c,b>g,c>e,c>h,d>f,d>g
find_18(a,b,c,d,e,f,g,h) =
  if c > d
  then find_23(e,a,d,h)
  else find_23(f,b,c,g)
# n=4, i=2, cost=3: b>c,b>d
find_23(a,b,c,d) =
  if a > c
  then find_21(a,b,d)
  else find_22(c,d)
# n=9, i=5, cost=5: a>h,a>i,b>d,b>g,c>e,c>i,d>f,d>i,e>g,e>h
find_16(a,b,c,d,e,f,g,h,i) =
  if a > d
  then find_24(c,b,a,e,d,f,h,g,i)
  else find_25(c,d,f,e,a,g,i)
# n=7, i=4, cost=4: a>d,a>g,b>c,b>e,d>f,e>g
find_25(a,b,c,d,e,f,g) =
  if c > d
  then find_26(c,e,a,g,d)
  else find_27(d,b,f,e,c,g)
# n=6, i=3, cost=3: a>c,a>e,b>d,b>e,d>f
find_27(a,b,c,d,e,f) =
  if c > d
  then find_21(c,b,e)
  else find_28(a,d,f,e)
# n=4, i=2, cost=2: a>d,b>c
find_28(a,b,c,d) =
  if a > b
  then find_22(b,d)
  else find_22(a,c)
# n=5, i=3, cost=3: a>e,b>d,c>d,c>e
find_26(a,b,c,d,e) =
  if a > b
  then find_21(b,c,e)
  else find_21(a,c,d)
# n=9, i=5, cost=4: a>d,a>i,b>e,b>h,c>e,c>g,d>g,d>h,e>f,e>i
find_24(a,b,c,d,e,f,g,h,i) =
  if d > e
  then find_20(b,c,g,h,e)
  else find_23(f,a,d,i)
# n=9, i=5, cost=6: a>g,b>g,b>h,c>d,c>e,d>f,e>h,g>i
find_14(a,b,c,d,e,f,g,h,i) =
  if a > d
  then find_29(b,c,a,e,d,g,h,f,i)
  else find_30(e,b,d,f,a,h,g)
# n=7, i=4, cost=5: a>f,b>f,b>g,c>d,c>e,e>g
find_30(a,b,c,d,e,f,g) =
  if a > b
  then find_31(c,a,d,e,b,f)
  else find_25(b,c,d,a,e,f,g)
# n=6, i=4, cost=4: a>c,a>d,b>e,e>f
find_31(a,b,c,d,e,f) =
  if c > e
  then find_32(d,c,b,e)
  else find_20(a,e,f,d,c)
# n=4, i=3, cost=3: b>d,c>d
find_32(a,b,c,d) =
  if a > b
  then find_33(b,c)
  else find_21(a,c,d)
# n=2, i=2, cost=1: no comparisons done
find_33(a,b) =
  if a > b
  then b
  else a
# n=9, i=5, cost=5: a>f,a>g,b>d,b>e,c>e,c>f,d>g,e>h,f>i
find_29(a,b,c,d,e,f,g,h,i) =
  if d > f
  then find_34(a,d,c,e,h,g,f)
  else find_35(a,b,e,f,i,h,d)
# n=7, i=4, cost=4: a>d,b>c,b>g,c>f,d>e,d>g
find_35(a,b,c,d,e,f,g) =
  if a > c
  then find_27(d,b,e,c,g,f)
  else find_21(f,a,d)
# n=7, i=4, cost=4: a>f,a>g,b>f,b>g,c>d,c>g,d>e
find_34(a,b,c,d,e,f,g) =
  if a > d
  then find_27(b,c,f,d,g,e)
  else find_36(a,b,e)
# n=3, i=2, cost=3: no comparisons done
find_36(a,b,c) =
  if a > b
  then find_21(c,a,b)
  else find_21(c,b,a)
# n=11, i=6, cost=9: a>f,b>h,c>e,c>j,d>g,d>h,g>i,g>j,j>k
find_10(a,b,c,d,e,f,g,h,i,j,k) =
  if a > b
  then find_37(c,a,d,f,e,b,g,i,h,j,k)
  else find_38(c,b,d,e,a,g,h,i,f,j,k)
# n=11, i=6, cost=8: a>d,a>j,b>e,b>g,c>f,c>g,e>i,f>h,f>j,j>k
find_38(a,b,c,d,e,f,g,h,i,j,k) =
  if d > h
  then find_39(b,a,c,e,d,f,g,i,j,h,k)
  else find_13(a,b,f,g,e,h,i,j,d,k)
# n=11, i=6, cost=7: a>d,a>g,b>e,b>i,c>f,c>g,d>h,e>j,f>i,f>j,i>k
find_39(a,b,c,d,e,f,g,h,i,j,k) =
  if e > g
  then find_40(a,c,b,d,e,f,h,i,g,j,k)
  else find_14(f,b,a,d,g,h,i,e,k)
# n=11, i=6, cost=6: a>d,a>i,b>f,b>i,c>e,c>h,d>g,e>i,e>j,f>h,f>j,h>k
find_40(a,b,c,d,e,f,g,h,i,j,k) =
  if d > h
  then find_41(c,b,a,d,e,f,g,i,j,h)
  else find_17(a,e,f,h,j,i,k,d)
# n=10, i=6, cost=5: a>e,a>j,b>f,b>h,c>d,c>h,d>g,d>j,e>h,e>i,f>i,f>j
find_41(a,b,c,d,e,f,g,h,i,j) =
  if d > e
  then find_42(g,b,a,e,f,h,j)
  else find_19(b,c,d,f,h,g,i)
# n=7, i=4, cost=4: b>e,b>f,c>d,c>g,d>f,e>g
find_42(a,b,c,d,e,f,g) =
  if a > d
  then find_43(a,c,b,e,d,g)
  else find_27(d,b,a,e,f,g)
# n=6, i=4, cost=3: a>e,b>e,b>f,c>d,d>f
find_43(a,b,c,d,e,f) =
  if a > d
  then find_44(b,c,d,e)
  else find_21(a,b,f)
# n=4, i=3, cost=2: a>d,b>c
find_44(a,b,c,d) =
  if c > d
  then find_33(a,c)
  else find_33(b,d)
# n=11, i=6, cost=8: a>e,a>j,b>d,b>f,c>g,c>i,f>i,g>h,g>j,j>k
find_37(a,b,c,d,e,f,g,h,i,j,k) =
  if e > h
  then find_45(b,a,c,d,f,e,g,i,j,h,k)
  else find_13(a,b,g,d,f,h,i,j,e,k)
# n=11, i=6, cost=7: a>d,a>e,b>f,b>i,c>g,c>h,e>h,f>j,g>i,g>j,i>k
find_45(a,b,c,d,e,f,g,h,i,j,k) =
  if d > f
  then find_46(b,a,c,d,e,g,h,f,i,k)
  else find_47(a,b,c,e,f,g,h,d,i,j,k)
# n=11, i=6, cost=6: a>d,a>h,b>e,b>i,c>f,c>g,d>g,e>h,e>j,f>i,f>j,i>k
find_47(a,b,c,d,e,f,g,h,i,j,k) =
  if d > i
  then find_48(b,c,a,e,d,f,h,g,j,i)
  else find_17(a,e,f,i,j,h,k,d)
# n=10, i=6, cost=5: a>d,a>j,b>f,b>h,c>e,c>g,d>g,d>i,e>h,e>j,f>i,f>j
find_48(a,b,c,d,e,f,g,h,i,j) =
  if d > e
  then find_25(b,c,g,f,e,i,h)
  else find_25(a,b,h,d,f,g,j)
# n=10, i=6, cost=6: a>h,a>i,b>d,b>e,c>f,c>g,d>h,e>g,f>i,i>j
find_46(a,b,c,d,e,f,g,h,i,j) =
  if d > f
  then find_49(e,a,c,d,g,h,f,i)
  else find_50(a,b,f,e,g,i,d,j,h)
# n=9, i=5, cost=5: a>f,a>i,b>d,b>g,c>f,c>g,d>e,f>h,g>i
find_50(a,b,c,d,e,f,g,h,i) =
  if d > f
  then find_51(a,d,c,e,g,f,i)
  else find_27(f,b,h,g,d,i)
# n=7, i=4, cost=4: a>f,a>g,b>d,b>f,c>e,c>f,e>g
find_51(a,b,c,d,e,f,g) =
  if d > e
  then find_26(a,d,c,e,f)
  else find_52(a,b,e,d,g,f)
# n=6, i=3, cost=3: a>e,a>f,b>d,b>f,c>d,c>e
find_52(a,b,c,d,e,f) =
  if a > b
  then find_28(b,c,e,f)
  else find_28(a,c,d,f)
# n=8, i=5, cost=5: a>e,b>f,b>h,c>e,c>g,d>f,d>g,g>h
find_49(a,b,c,d,e,f,g,h) =
  if a > g
  then find_53(b,d,c,a,f,e,g)
  else find_27(b,g,f,a,h,e)
# n=7, i=5, cost=4: a>e,b>e,b>g,c>f,c>g,d>f,d>g
find_53(a,b,c,d,e,f,g) =
  if e > f
  then find_54(a,c,d,e,g)
  else find_55(a,f,b,g)
# n=4, i=3, cost=3: c>d
find_55(a,b,c,d) =
  if a > b
  then find_44(a,c,d,b)
  else find_44(b,c,d,a)
# n=5, i=4, cost=3: a>d,b>e,c>e
find_54(a,b,c,d,e) =
  if b > c
  then find_44(a,c,e,d)
  else find_44(a,b,e,d)
"""

def get_return(fn_name, fn_args, part):
    if fn_name != None:
        tmpargs = fn_args.split(',')
        tmp_actual_args = ''
        actual_args = ''
        for p in tmpargs:
            tmp_actual_args += f'{p}i,'
            actual_args += f'{p},'
        return f'return **{fn_name}**({tmp_actual_args}{actual_args}r)'
    else:
        return f'return {part}'

# // find_54 *******************
# function select_3_5_da_eb_ec(ai,bi,ci,di,ei,a,b,c,d,e,r) {
#     cmp = compare_strict_or_reflexive(bi < ci)
#     if (cmp.call(b, c, r)) return select_2_4_da_cb(ai,ci,ei,di,a,c,e,d,r)
#     return select_2_4_da_cb(ai,bi,ei,di,a,b,e,d,r)
# }


def process(n,i,cost,comps,fn_name,fn_args,var1,var2,if_part,else_part, functions_aliases):

    k = int(i) - 1

    fn_name_if = None
    fn_args_if = None
    s = re.search('(\w+)\(([^\)]+)\)', if_part, re.IGNORECASE)
    if s:
        fn_name_if = s.group(1)
        fn_args_if = s.group(2)

    fn_name_else = None
    fn_args_else = None
    s = re.search('(\w+)\(([^\)]+)\)', else_part, re.IGNORECASE)
    if s:
        fn_name_else = s.group(1)
        fn_args_else = s.group(2)

    args = fn_args.split(',')
    stability_indices = ''
    parameters = ''
    for p in args:
        stability_indices += f'{p}i,'
        parameters += f'{p},'

    return_if = get_return(fn_name_if, fn_args_if, if_part)
    return_else = get_return(fn_name_else, fn_args_else, else_part)

    new_func_name = f'select_{k}_{n}'
    if comps != 'no comparisons done':
        # print(comps)
        # n=8, i=5, cost=5: a>e,b>f,b>h,c>e,c>g,d>f,d>g,g>h
        comps_list = comps.split(',')
        for p in comps_list:
            new_func_name += f'_{p[2]}{p[0]}'

    functions_aliases[fn_name] = new_func_name

#  template <int ia, int ib, Regular T, Regular U, StrictWeakOrdering R>
#      requires(Same<T, U> && Domain<R, T>)
#  inline constexpr
#  auto select_0_2(T&& a, U&& b, R r) FN(
#      CMP((ia < ib), R)(b, a, r) ? _b : _a
#  )
#  # n=2, i=1, cost=1: no comparisons done
#  find_22(a,b) =
#    if a > b
#    then a
#    else b

    code  = f'// {fn_name} ******************* \n'
    code += f'function {new_func_name}({stability_indices}{parameters}r)' + '{\n'
    code += f'    cmp = new compare_strict_or_reflexive({var1}i < {var2}i);\n'
    code += f'    if (cmp.call({var2}, {var1}, r))\n        {return_else};\n'
    code += f'    {return_if};\n'
    code += '}\n\n'


    # code  = f'// {fn_name} ******************* \n'
    # code += f'function {new_func_name}({stability_indices}{parameters}r)' + '{\n'
    # code += f'    cmp = compare_strict_or_reflexive({var1}i < {var2}i);\n'
    # code += f'    if (cmp.call({var1}, {var2}, r)) {return_if};\n'
    # code += f'    {return_else};\n'
    # code += '}\n\n'

    return code


def main():

    functions_aliases = {}
    new_code = ''

    state = 0
    for line in code.splitlines():
        if state == 0:
            s = re.search('# n=(\d+), i=(\d+), cost=(\d+): ([^\n]*)', line, re.IGNORECASE)
            if s:
                state = 1
                n = s.group(1)
                i = s.group(2)
                cost = s.group(3)
                comps = s.group(4)
        elif state == 1:
            s = re.search('(\w+)\(([^\)]+)\) =', line, re.IGNORECASE)
            if s:
                state = 2
                fn_name = s.group(1)
                fn_args = s.group(2)
        elif state == 2:
            s = re.search('  if (.) > (.)', line, re.IGNORECASE)
            if s:
                state = 3
                var1 = s.group(1)
                var2 = s.group(2)
        elif state == 3:
            s = re.search('  then ([^\n]+)', line, re.IGNORECASE)
            if s:
                state = 4
                if_part = s.group(1)
        elif state == 4:
            s = re.search('  else ([^\n]+)', line, re.IGNORECASE)
            if s:
                state = 0
                else_part = s.group(1)

                new_funct_code = process(n,i,cost,comps,fn_name,fn_args,var1,var2,if_part,else_part, functions_aliases)
                new_code = new_funct_code + new_code

    for k,v in functions_aliases.items():
        # print(k)
        # print(v)
        new_code = new_code.replace(f'**{k}**', v)

    # print(functions_aliases)
    print(new_code)

main()