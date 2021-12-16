# Data_Structure
- 2021 / 12 / 16
    - 인명록 작성 콘솔 프로그램


# 깃허브 요약

- staged 란
> 눈에 보이지 않는, 각 branch에 올라가기 전 임시 저장소

- Branch
> 개발용 코드 버전 생성
> 추후 master에 합치는 용도로 사용

- Add, Commit, Push
> 추가, 갱신, 업로드

- Fork
> Fork 는 자신의 저장소로 다른 사람의 프로젝트를 통째로 복사 하는 행위

- Clone
> 원격 저장소 | 파일 복사 행위

- Commit
> 개인이 작성한 코드를 임시 저장소에 올려둠 (staged)

- Push
> 임시로 commit된 내역을, 내가 현재 지정한 branch로 반영하기 위한 작업
> commit 만 한 채로 git에서 branch를 조회하면 소스 반영이 안되어 있으나, push를 하고나면 반영된 내용 확인 가능

- Merge
> branch 간 소스코드 병합
> develop -> master 로의 병합도 포함

- Merge Request
> 팀 프로젝트 간 함부로 merge되는 것을 방지하게 설정된 branch에 내 작업 내역을 Merge하기 위하여 승인 권한을 가진 구성원의 승인을 받는 절차

- Pull
> 현재 내 로컬에 받아진 저장소의 소스코드를 git과 현행화(일치, download)하기 위한 작업
> mode로는 rebase(교체), merge(병합) 이 가능

- Pull Request
> Merge Request와 유사하게, Pull을 수행하기 위한 승인 절차
> 자신이 수정한 파일을 다른 사람 프로젝트에 반영 요청하는 것
> 상대방이 마음에 들면 그것을 merge 함

- Conflict
> 2명 이상이 동일한 파일을 수정했는데, 그 파일 수정한 부분 또한 겹쳐서 소스 충돌이 일어나는 경우
> 흔히 팀 프로젝트에서는 '컨플릭 났다!!!!' 라고 외침