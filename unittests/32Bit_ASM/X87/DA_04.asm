%ifdef CONFIG
{
  "RegData": {
    "XMM0":  ["0x8000000000000000", "0xBFFF"],
    "XMM1":  ["0xC000000000000000", "0x4000"]
  },
  "Mode": "32BIT"
}
%endif

lea edx, [.data]

fld qword [edx + 8 * 0]
fisub dword [edx + 8 * 1]
fstp tword [rel data2]
movups xmm0, [rel data2]

; Test negative
lea edx, [.data_neg]

fld qword [edx + 8 * 0]
fisub dword [edx + 8 * 1]
fstp tword [rel data2]
movups xmm1, [rel data2]

hlt

.data:
dq 0x3ff0000000000000
dq 2

.data_neg:
dq 0x3ff0000000000000
dq -2

data2:
dq 0
dq 0
