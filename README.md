# ConsoleMVC-MINGOO-21015010

콘솔 애플리케이션에서 Model / View / Controller 역할을 명확히 분리한 최소 골격(Skeleton) PoC.

Main 프로젝트 [`SampleOrderSystem-MINGOO-21015010`](https://github.com/kangtop729/SampleOrderSystem-MINGOO-21015010)의
"MVC 역할 분리 구조" 기술 요소를 검증하기 위한 참고용 산출물이다.

## 목적

- "메뉴 입력 → 처리 → 화면 출력"이라는 흐름을 Model/View/Controller로 분리한 구조를 검증한다.
- View를 Mock으로 교체해도 Controller를 테스트할 수 있는 DI 가능한 구조를 실험한다.

## 구조

```
ConsoleMVC-MINGOO-21015010/
├── src/
│   ├── Model/         # 데이터 상태를 표현하는 순수 클래스
│   ├── View/          # 콘솔 입출력 담당
│   ├── Controller/    # Model과 View를 연결, 흐름 제어
│   └── main.cpp       # 진입점
├── test/              # gmock 기반 단위 테스트
├── CLAUDE.md           # 에이전트 작업 규칙
├── PLAN.md             # 구현 계획
└── README.md
```

자세한 구현 계획은 [`PLAN.md`](PLAN.md) 참고.

## 빌드 및 실행

```
msbuild ConsoleMVC-MINGOO-21015010.vcxproj /p:Configuration=Debug /p:Platform=x64
```

(빌드 프로젝트 구성 후 갱신 예정)
