from typing import List

def MergeSort(sequence:List[int]) -> None:
  
  def merge(lo:int, hi:int, mid:int):
    new = [];
    l = lo;
    r = mid+1;
    while l <= mid and r <= hi:
      if sequence[l] > sequence[r]:
        new.append(sequence[r]);
        r += 1;
      else:
        new.append(sequence[l]);
        l += 1;

    while l <= mid:
      new.append(sequence[l]);
      l += 1;
    
    while r <= hi:
      new.append(sequence[r]);
      r += 1;

    for element in new:
      sequence[lo] = element;
      lo += 1;


  def part(lo:int, hi:int) -> None:
    if hi <= lo: return;
    mid = (hi + lo) // 2;
    part(lo, mid);
    part(mid+1, hi);
    merge(lo, hi, mid);

  part(0, len(sequence)-1);

def main() -> None:
  myList:List[int] = [ 5, 7, 1, 2, 6, 0, -2, -6, -1, 8, 9, 10, 2 ];
  print(myList);
  MergeSort(myList);
  print(myList);

if (__name__ == '__main__'):
  main();